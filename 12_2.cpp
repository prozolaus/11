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

    vector<string> vstr;
    while (true)
    {
        getline(ifs, line);
        if (!ifs)
            break;
        vstr.push_back(line);
    }
    for (int i = vstr.size() - 1; i >= 0; i--)
    {
        string s = vstr[i];
        for (int j = s.size() - 1; j >= 0; j--)
            ofs << s[j];
        ofs << endl;
    }
    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
