#include "std_lib_facilities.h"

int main()
try
{
    string iname{"x"}, line;
    ifstream ifs{iname};
    if (!ifs)
        error("Unable to open input file ", iname);

    string oname = "y";
    ofstream ofs{oname};
    if (!ofs)
        error("Unable to open output file ", oname);

    istringstream is;
    vector<double> vd;
    double d;
    int count = 0;
    while (true)
    {
        getline(ifs, line);
        if (!ifs)
            break;
        is.str(line);
        is >> d;
        if (!is)
            error("Input error!");
        count++;
        ofs << scientific << setprecision(8) << setw(20) << d;
        if (count==4)
        {
            count = 0;
            ofs << endl;
        }
        is.clear();
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
