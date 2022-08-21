#include "std_lib_facilities.h"

bool is_whitespace(char ch)
{
    string white = ".;,?-'";
    for (const char &w : white)
        if (ch == w)
            return true;
    return false;
}

void tolower(string &s)
{
    for (char &x : s)
        x = tolower(x);
}

void rplc(string &src, const string &s1, const string &s2)
{
    int i = 0;
    while (true)
    {
        i = src.find(s1, i);
        if (i > -1)
            src.replace(i, s1.size(), s2);
        else
            return;
    }
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

    string s1 = "don't";
    string ss1 = "do not";
    string s2 = "can't";
    string ss2 = "can not";

    while (ifs)
    {
        getline(ifs, line);
        if (!ifs)
            break;

        tolower(line);

        rplc(line, s1, ss1);
        rplc(line, s2, ss2);

        char ch;
        for (int i = 0; i < line.size(); i++)
            if (is_whitespace(line[i]))
            {
                if (line[i] == '-' && isalpha(line[i - 1]) && isalpha(line[i + 1]))
                    continue;
                line[i] = ' ';
            }

        ofs << line << endl;
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
