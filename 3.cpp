#include "std_lib_facilities.h"

bool isvowel(char ch)
{
    ch = tolower(ch);
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    }
    return false;
}

int main()
{
    string iname = "x";
    ifstream ifs{iname};
    if (!ifs)
        error("Unable to open input file ", iname);

    string oname = "y";
    ofstream ofs{oname};
    if (!ofs)
        error("Unable to open output file ", oname);

    for (char ch; ifs.get(ch);)
        if (!isvowel(ch))
            ofs << ch;

}