#ifndef XYZPARSER_H
#define XYZPARSER_H
#include <iostream>
#include <string>
#include "file.h"
#include "atom.h"
#include<vector>

class XYZ
{
public:
    static std::vector<Atom> getAtoms(const char* path);
    static std::string getName(const char* path);
};

#endif