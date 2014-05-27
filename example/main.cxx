#include "CppConf/CppConf.hpp"

int main(int argc, char* argv[])
{
    CppConf conf = CppConf();
    return conf.FromFile("config.cfg");
}
