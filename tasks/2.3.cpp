#include "std_lib_facilities.h"

int main()
try
{
    double d = 1.23456789;
    cout << d << '\t' << fixed << d << '\t' << scientific << d << endl;
    cout << defaultfloat << setprecision(7) << d << '\t' << fixed << setprecision(7) << d << '\t' << scientific << setprecision(7) << d << endl;
    cout << defaultfloat << setprecision(2) << d << '\t' << fixed << setprecision(2) << d << '\t' << scientific << setprecision(2) << d << endl;
    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
