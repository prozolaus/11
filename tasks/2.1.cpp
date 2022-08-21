#include "std_lib_facilities.h"

int main()
try
{
    cout << showbase;
    //cout << noshowbase;
    cout << "decimal:\t" << 25 << "\t" << 12 << "\t" << 1996 << endl;
    cout << "hexadecimal:\t" << hex << 25 << "\t" << 12 << "\t" << 1996 << endl;
    cout << "octal:\t\t" << oct << 25 << "\t" << 12 << "\t" << 1996 << endl;
    return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
