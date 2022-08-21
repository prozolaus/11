#include "std_lib_facilities.h"

int main()
try
{
    string iname{"x"};
    ifstream ifs{iname};
    if (!ifs)
        error("Unable to open input file ", iname);

    string oname = "y";
    ofstream ofs{oname, ios_base::binary};
    if (!ofs)
        error("Unable to open output file ", oname);

    vector<char> v;

    for (char ch; ifs.get(ch);)
        v.push_back(ch);

    for (char x : v)
        ofs.write(as_bytes(x), sizeof(int));

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
