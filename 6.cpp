#include "std_lib_facilities.h"

bool is_whitespace(char ch)
{
    string white = ".;,?-'";
    for (const char &w : white)
        if (ch == w)
            return true;
    return false;
}

int main()
try
{
    string iname{"x"}, line;
    ifstream ifs{iname};
    if (!ifs)
        error("Unable to open input file ", iname);

    string oname = "y";
    ofstream ofs{oname};
    if (!ofs)
        error("Unable to open output file ", oname);

    getline(ifs, line);

    for (char &ch : line)
        if (is_whitespace(ch))
            ch = ' ';

    ofs << line;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
