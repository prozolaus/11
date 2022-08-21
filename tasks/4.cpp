#include "std_lib_facilities.h"

double str_to_double(string s)
{
    istringstream is{s};
    double d;
    is >> d;
    if (!is)
        error("Error of double: ", s);
    return d;
}

int main()
try
{
    cout << str_to_double("12.4") << endl;
    cout << str_to_double("1.34e-3") << endl;
    cout << str_to_double("twelve") << endl;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
