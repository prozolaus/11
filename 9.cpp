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

    vector<int> v;

    for (int x; ifs.read(as_bytes(x), sizeof(int));)
        v.push_back(x);

    for (int x : v)
        ofs.write(as_bytes(x), sizeof(int));

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
