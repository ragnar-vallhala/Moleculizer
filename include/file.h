
#ifndef FILE_H
#define FILE_H
#include <string>
#include<fstream>
#include <sstream>

#ifdef DEBUG
#include <iostream>
#endif
#include "shader.h"

void readFile(const char* path, std::string& str);
#endif