#include "file.h"

void readFile(const char* path, std::string& str)
{
	std::ifstream in;
	in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		in.open(path);
		std::stringstream stream;
		stream << in.rdbuf();
		str = stream.str();
		in.close();
	}
	catch(std::ifstream::failure e){
		#ifdef DEBUG
        std::cout<<"File Loading Failed: "<<e.what()<<std::endl;
        #endif
	}
}