#include "std_lib_facilities.h"

int main()
try
{
    string iname{"x"};
    ifstream ifs{iname, ios_base::binary};
    string oname{"y"};
    ofstream ofs{oname, ios_base::binary};

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
