#include "xyzParser.h"



std::vector<Atom> XYZ::getAtoms(const char* path)
{
    std::string content;
    readFile(path,content); 
// #ifdef DEBUG
//     std::cout<<content<<std::endl;
// #endif
    std::vector<Atom> atoms;
    std::stringstream ss(content);
    std::string line;
    int count{};
    while (std::getline(ss, line)) 
    {
        count++;
        if(count<3) continue;
        std::stringstream ss2(line);
        std::string atomName;
        float x,y,z;
        ss2>>atomName>>x>>y>>z;
        atoms.push_back(Atom(x,y,z,0.01f,atomName));
        
    }


    return atoms;
}
std::string XYZ::getName(const char *path)
{
    std::string content;
    readFile(path,content);
    std::string name;
    int begin{},end{};
    int count{};
    begin = (int)content.find_first_of("\n",0);
    end = (int)content.find_first_of("\n",begin+1);
    name = content.substr(begin+1,end-begin-1);
    return name;
}
