#pragma once

#include <unordered_map>

#include "Graphics.hpp"

class ShaderProgram {
	private:
		guint programName;
		guint vertName;
		guint fragName;
		bool errorFlag;
		std::unordered_map<char *, guint> propertyNames;
	public:
		static const guint POSITION_BINDLOC = 0;
		ShaderProgram(std::string);
		bool error() { return errorFlag; }
		void use();
};