#include "std_lib_facilities.h"

int main()
try
{
    string iname{"x"};
    ifstream ifs{iname};
    string oname{"y"};
    ofstream ofs{oname};

    for (char ch; ifs.get(ch);)
        ofs << (char)tolower(ch);

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
