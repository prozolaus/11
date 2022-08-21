#include "std_lib_facilities.h"


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

    for (int i = line.size() - 1; i >= 0; i--)
        ofs << line[i];
    ofs << endl;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
