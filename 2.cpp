#include "std_lib_facilities.h"

void tolower(string &s)
{
    for (char &x : s)
        x = tolower(x);
}

int main()
try
{
    string iname{"x"}, word{"true"}, line, s;
    ifstream ifs{iname};
    istringstream buffer;
    if (!ifs)
        error("Unable to open input file, ", iname);
    tolower(word);

    for (int i = 1; ifs.good(); i++)
    {
        getline(ifs, line);
        buffer.str(line);
        while (buffer >> s)
        {
            tolower(s);
            if (s == word)
                cout << "Line #" << i << ": " << line << endl;
        }
        buffer.clear();
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
