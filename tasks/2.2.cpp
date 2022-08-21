#include "std_lib_facilities.h"

int main()
try
{
    int a, b, c, d;
    //cin >> a >> hex >> b >> oct >> c >> d;
    cin.unsetf(ios::dec);
    //cin.unsetf(ios::oct);
    //cin.unsetf(ios::hex);
    cin >> a >> b >> c >> d;
    cout << a << "\t" << b << "\t" << c << '\t' << d << endl;
    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
