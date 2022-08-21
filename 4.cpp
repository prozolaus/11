#include "std_lib_facilities.h"

int main()
try
{
    string iname{"x"}, line;
    ifstream ifs{iname};
    if (!ifs)
        error("Unable to open input file ", iname);
    int i;
    istringstream is;
    is.unsetf(ios::dec);

    while (ifs)
    {
        bool hexi = false, octi = false;

        ifs >> line;
        if (!ifs)
            break;

        if (line[0] == '0')
        {
            if (line[1] == 'x')
                hexi = true;
            else
                octi = true;
        }

        is.str(line);
        is >> i;
        if (!is)
            error("Error of input!");
        is.clear();

        cout << line;

        if (hexi)
            cout << " (hex)";
        else if (octi)
            cout << " (oct)";
        else
            cout << " (dec)";

        cout << " turns into decimal " << i << endl;
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
