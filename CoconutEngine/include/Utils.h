#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

namespace Coco
{
// code for this function taken from
// https://github.com/VictorGordan/opengl-tutorials/blob/main/YoutubeOpenGL%204%20-%20Organizing
	std::string get_file_contents(const char* filename);
}