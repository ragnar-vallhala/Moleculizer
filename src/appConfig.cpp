#include "appConfig.h"

Configuration::Configuration()
{
    std::ifstream file("moleculizer.conf");
    if(file.is_open())
    {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        std::stringstream lines{content};
            float f;
            std::string s;
            bool b;

            lines>>f;
            m_position.x=f;
            lines>>f;
            m_position.y=f;
            lines>>f;
            m_position.z=f;

            lines>>f;
            m_rotation.x=f;
            lines>>f;
            m_rotation.y=f;
            lines>>f;
            m_rotation.z=f;

            lines>>f;
            m_radius=f;

            lines>>f;
            m_bgColor.r=f;
            lines>>f;
            m_bgColor.g=f;
            lines>>f;
            m_bgColor.b=f;
            lines>>f;
            m_bgColor.a=f;

            lines>>s;
            m_moleculePath=s;
            lines>>s;
            m_selectedPath=s;

            lines>>b;
            m_showDialog=b;
            lines>>b;
            m_showControl=b;
            lines>>b;
            m_showFPS=b;


            
            
        
        
    }
    else
    {

        std::cout<<"No config found!"<<std::endl;
    }
}

Configuration::~Configuration()
{
    //Inorder writing
    std::ofstream file("moleculizer.conf");
    if(file.is_open())
    {
        std::string content;
        
        content+=std::to_string(m_position.x);
        content+="\n";
        content+=std::to_string(m_position.y);
        content+="\n";
        content+=std::to_string(m_position.z);
        content+="\n";

        
        content+=std::to_string(m_rotation.x);
        content+="\n";
        content+=std::to_string(m_rotation.y);
        content+="\n";
        content+=std::to_string(m_rotation.z);
        content+="\n";

        content+=std::to_string(m_radius);
        content+="\n";

        content+=std::to_string(m_bgColor.r);
        content+="\n";
        content+=std::to_string(m_bgColor.g);
        content+="\n";
        content+=std::to_string(m_bgColor.b);
        content+="\n";
        content+=std::to_string(m_bgColor.a);
        content+="\n";

        content+=m_moleculePath;
        content+="\n";

        content+=m_selectedPath;
        content+="\n";

        content+=std::to_string(m_showDialog);
        content+="\n";
        content+=std::to_string(m_showControl);
        content+="\n";
        content+=std::to_string(m_showFPS);

        file<<content;
        file.close();
    }

}