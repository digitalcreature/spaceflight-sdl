
#define _CRT_SECURE_NO_WARNINGS	//i blame microsoft for this bullshit
#include <cstdio>

#include "fileutil.hpp"

char *fileutil::text(const char *fname) {
	FILE *file = fopen(fname, "rb");
	if (file) {
		fseek(file, 0, SEEK_END);
		size_t length = ftell(file);
		fseek(file, 0, SEEK_SET);
		char *text = new char[length + 1];
		fread(text, sizeof(char), length, file);
		text[length] = '\0';
		fclose(file);
		return text;
	}
	return NULL;
}