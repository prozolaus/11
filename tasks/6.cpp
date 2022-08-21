#include "std_lib_facilities.h"

void tolower(string &s)
{
    for (char &x : s)
        x = tolower(x);
}

int main()
try
{
    string s{"TEXT"};
    cout << s << endl;
    tolower(s);
    cout << s << endl;
    
    char ch = 'X';
    cout << ch << endl;
    ch = tolower(ch);
    cout << ch << endl;
    

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
