#include "std_lib_facilities.h"

bool is_whitespace(char ch, const string &white)
{
    for (const char &w : white)
        if (ch == w)
            return true;
    return false;
}

vector<string> split(const string &s, const string &w)
{
    string line = s;
    for (char &ch : line)
        if (is_whitespace(ch, w))
            ch = ' ';

    vector<string> vs;
    istringstream is{line};
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
        const string white = ".;,?!-";
        vector<string> vs = split(vstr[i], white);

        for (int i = vs.size() - 1; i >= 0; i--)
            ofs << vs[i] << ' ';
        ofs << endl;
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
