
#include "GL.hpp"
#include "ShaderProgram.hpp"
#include "fileutil.hpp"

bool loadShader(GLenum type, guint& name, std::string sourceName, char* inc = "") {
	name = glCreateShader(type);
	char *source = fileutil::text(sourceName.c_str());
	if (!source) return false;
	char *sources[] = {inc, source};
	glShaderSource(name, 2, sources, NULL);
	glCompileShader(name);
	delete[] source;
	return true;
}

ShaderProgram::ShaderProgram(std::string source)
	: propertyNames() {
	errorFlag = false;
	if (!loadShader(GL_VERTEX_SHADER, vertName, source + ".vert")) {
		errorFlag = true;
		return;
	}
	if (!loadShader(GL_FRAGMENT_SHADER, fragName, source + ".frag")) {
		errorFlag = true;
		return;
	}
	programName = glCreateProgram();
	glAttachShader(programName, vertName);
	glAttachShader(programName, fragName);
	glBindAttribLocation(programName, POSITION_BINDLOC, "position");
	glLinkProgram(programName);
}

void ShaderProgram::use() {
	glUseProgram(programName);
}

//TODO: Shader Program error checking: GET SHADERS WORKING