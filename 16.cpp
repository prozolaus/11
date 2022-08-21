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
    vector<int> vi;
    int n;

    while (true)
    {
        ifs >> line;
        if (!ifs)
            break;
        is.str(line);
        is >> n;
        if (!is)
            error("Input error!");
        vi.push_back(n);
        is.clear();
    }

    sort(vi.begin(), vi.end());
    
    for (int i = 0, count; i < vi.size(); i++)
    {
        count = 1;
        while (i < vi.size() - 1 && vi[i] == vi[i + 1])
        {
            count++;
            i++;
        }
        ofs << vi[i];
        if (count > 1)
            ofs << ' ' << count;
        ofs << endl;
    }

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
