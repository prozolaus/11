#include "std_lib_facilities.h"

vector<string> split(const string& s)
{
    vector<string> vs;
    istringstream is{s};
    for (string word; is >> word;)
        vs.push_back(word);
    return vs;
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

    vector<string> vs = split(line);

    for (int i = 0; i < vs.size(); i++)
        ofs << vs[i] << endl;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
