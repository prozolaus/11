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
    string s3 = "i'm";
    string ss3 = "i am";

    vector<string> vs;
    istringstream is;

    while (ifs)
    {
        getline(ifs, line);
        if (!ifs)
            break;

        tolower(line);

        rplc(line, s1, ss1);
        rplc(line, s2, ss2);
        rplc(line, s3, ss3);

        char ch;
        for (int i = 0; i < line.size(); i++)
            if (is_whitespace(line[i]))
            {
                if (line[i] == '-' && isalpha(line[i - 1]) && isalpha(line[i + 1]))
                    continue;
                line[i] = ' ';
            }

        is.str(line);
        for (string word; is >> word;)
            vs.push_back(word);
        is.clear();
    }
    sort(vs.begin(), vs.end());

    for (int i = 0; i < vs.size(); i++)
        if (i == 0 || vs[i] != vs[i - 1])
            ofs << vs[i] << endl;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
