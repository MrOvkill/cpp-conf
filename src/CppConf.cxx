#include "CppConf/CppConf.hpp"

using namespace std;

CppConf::CppConf()
{
    values = map<string, string>();
}

int CppConf::FromFile(string name)
{
    FILE* f = fopen(name.c_str(), "r");
    string stuff = "";
    if(f)
    {
        char c = ' ';
        while(c != EOF)
        {
            stuff += c;
            c = fgetc(f);
        }
        Parse(stuff);
        return 1;
    }
    else
    {
        return 0;
    }
}

void CppConf::FromString(string content)
{
    Parse(content);
}

void CppConf::Parse(string str)
{
    const char* content = str.c_str();
    for(int i = 0; i < str.size(); i++)
    {
        if(content[i] == '$')
        {
            string key = "";
            
            do
            {
                i++;
                if(content[i] != '{')
                {
                    key += content[i];
                }
            } while(content[i] != '{');
            
            string value = "";
            
            do
            {
                i++;
                if(content[i] != '}')
                {
                    value += content[i];
                }
            } while(content[i] != '}');
            
            values[key] = value;
            printf("Values[\"%s\"] = \"%s\"\n", key.c_str(), value.c_str());
        }
    }
}
