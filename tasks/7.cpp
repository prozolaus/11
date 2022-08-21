#include "std_lib_facilities.h"

class Punct_stream
{
public:
    Punct_stream(istream &is)
        : source{is}, sensitive{true} {}

    void whitespace(const string &s) { white = s; }
    void add_white(char c) { white += c; }
    bool is_whitespace(char c);

    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    Punct_stream &operator>>(string &s);
    operator bool();

private:
    istream &source;
    istringstream buffer;
    string white;
    bool sensitive;
};

Punct_stream &Punct_stream::operator>>(string &s)
{
    while (!(buffer >> s))
    {
        if (buffer.bad() || !source.good())
            return *this;
        buffer.clear();

        string line;
        getline(source, line);

        for (char &ch : line)
            if (is_whitespace(ch))
                ch = ' ';
            else if (!sensitive)
                ch = tolower(ch);

        buffer.str(line);
    }
    return *this;
}

bool Punct_stream::is_whitespace(char ch)
{
    for (char w : white)
        if (ch == w)
            return true;
    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}

int main()
try
{
    ifstream ifs{"x"};
    if (!ifs)
        error("unable to open input file");
    Punct_stream ps{ifs};
    //Punct_stream ps{cin};

    ps.whitespace(";:,.?!()\"{}<>/&$@%^*|~");

    ps.case_sensitive(false);

    vector<string> vs;
    for (string word; ps >> word;)
        vs.push_back(word);
    sort(vs.begin(), vs.end());

    for (int i = 0; i < vs.size(); ++i)
        if (i == 0 || vs[i] != vs[i - 1])
            cout << vs[i] << endl;

    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
