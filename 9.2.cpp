#include "std_lib_facilities.h"

int main()
try
{
    string iname{"y"};
    ifstream ifs{iname, ios_base::binary};
    if (!ifs)
        error("Unable to open input file ", iname);

    string oname = "z";
    ofstream ofs{oname};
    if (!ofs)
        error("Unable to open output file ", oname);

    vector<int> v;

    for (int x; ifs.read(as_bytes(x), sizeof(int));)
        v.push_back(x);

    for (char x : v)
        ofs << x;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
