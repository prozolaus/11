#include "std_lib_facilities.h"

int main()
try
{
    string name{"x"};
    fstream fs{name};
    if (!fs)
        error("Unable to open input file", name);
    fs.seekg(5);

    char ch;
    fs >> ch;
    cout << "The sixth symbol is " << ch << '(' << int(ch) << ")\n";

    fs.seekp(1);
    fs << 'y';


    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
