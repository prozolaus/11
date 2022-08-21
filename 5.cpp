#include "std_lib_facilities.h"

int main()
try
{
    string iname{"x"}, line;
    ifstream ifs{iname};
    if (!ifs)
        error("Unable to open input file ", iname);

    while (true)
    {
        getline(ifs, line);
        if (!ifs)
            break;
        for (int i = 0; i < line.size(); i++)
        {
            char ch = line[i];
            cout << '\'' << ch << "\' belongs to: ";
            if (isspace(ch))
                cout << "space ";
            else if (isalnum(ch))
            {
                cout << "alnum ";
                if (isdigit(ch))
                    cout << "digit ";
                if (isxdigit(ch))
                    cout << "xdigit ";
                if (isalpha(ch))
                {
                    cout << "letter ";
                    if (isupper(ch))
                        cout << "upper_case ";
                    else
                        cout << "lower_case ";
                }
            }
            else if (iscntrl(ch))
                cout << "control ";
            else if (ispunct(ch))
                cout << "punct ";
            cout << endl;
        }
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
