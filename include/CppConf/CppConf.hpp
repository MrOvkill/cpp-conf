#ifndef CppConf_H
#define CppConf_H

#define CppConf_Revision 0

#include <string>
#include <map>
#include <cstdio>

using namespace std;

class CppConf
{
    private:
        void Parse(string str);
    public:
        map<string, string> values;

        CppConf();
        int FromFile(string name);
        void FromString(string content);
};

#endif
