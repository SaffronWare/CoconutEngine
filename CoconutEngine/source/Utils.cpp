#include "Utils.h"

namespace Coco
{
	std::string get_file_contents(const char* filename)
	{
		std::string actual_path = filename;
		std::ifstream in(actual_path, std::ios::binary);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();
			return(contents);
		}
		throw(errno);
	}
}