#include "Shader.h"

Shader::Shader() {}

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	Load(vertexPath, fragmentPath);
}

Shader::~Shader()
{

}

void Shader::Load(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	std::string vertexCodeStr;
	std::string fragmentCodeStr;
	const char *vertexCode;
	const char *fragmentCode;
	std::ifstream vertexFile;
	std::ifstream fragmentFile;

	vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);

		std::stringstream vertexStream, fragmentStream;

		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();

		vertexCodeStr = vertexStream.str();
		fragmentCodeStr = fragmentStream.str();

		vertexFile.close();
		fragmentFile.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "[Engine::Shader ERROR] Unable to open shader files. One of `" << vertexPath << "`, `" << fragmentPath << "` was not found." << std::endl;
		exit(EXIT_FAILURE);
	}

	vertexCode = vertexCodeStr.c_str();
	fragmentCode = fragmentCodeStr.c_str();

	GLuint vertex, fragment;
	int success;
	GLchar infoLog[512];

	memset(&infoLog, '.', sizeof(infoLog));
	infoLog[511] = 0;

	/* Compile vertex shader */
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "[Engine::Shader ERROR] Unable to compile vertex shader." << std::endl;
		std::cout << infoLog << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Compile fragment shader */
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragmentCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "[Engine::Shader ERROR] Unable to compile fragment shader." << std::endl;
		std::cout << infoLog << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Link program */
	programId = glCreateProgram();
	glAttachShader(programId, vertex);
	glAttachShader(programId, fragment);
	glLinkProgram(programId);

	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programId, 512, NULL, infoLog);
		std::cout << "[Engine::Shader ERROR] Unable to link shader program." << std::endl;
		std::cout << infoLog << std::endl;
		exit(EXIT_FAILURE);
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::Use()
{
	glUseProgram(programId);
}

void Shader::SetBool(const std::string &name, GLboolean value)
{
	glUniform1i(glGetUniformLocation(programId, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, GLint value)
{
	glUniform1i(glGetUniformLocation(programId, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, GLfloat value)
{
	glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
}
