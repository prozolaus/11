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

    int space = 0, alnum = 0, digit = 0, xdigit = 0, letter = 0, upper = 0, lower = 0, cntrl = 0, punct = 0;

    while (true)
    {
        getline(ifs, line);
        if (!ifs)
            break;
        for (int i = 0; i < line.size(); i++)
        {
            char ch = line[i];
            if (isspace(ch))
                space++;
            else if (isalnum(ch))
            {
                alnum++;
                if (isdigit(ch))
                    digit++;
                if (isxdigit(ch))
                    xdigit++;
                if (isalpha(ch))
                {
                    letter++;
                    if (isupper(ch))
                        upper++;
                    else
                        lower++;
                }
            }
            else if (iscntrl(ch))
                cntrl++;
            else if (ispunct(ch))
                punct++;
        }
    }
    ofs << "space: " << space << endl;
    ofs << "alnum: " << alnum << endl;
    ofs << "digit: " << digit << endl;
    ofs << "xdigit: " << xdigit << endl;
    ofs << "letter: " << letter << endl;
    ofs << "upper: " << upper << endl;
    ofs << "lower: " << lower << endl;
    ofs << "control: " << cntrl << endl;
    ofs << "punct: " << punct << endl;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
