#include "std_lib_facilities.h"

struct People
{
    string last_name;
    string first_name;
    long tel;
    string email;
};


int main()
try
{
    vector<People> my_friends;
    my_friends.push_back({"Bereshchanskyi", "Maksym", 34656535035, "bmw@gmail.com"});
    my_friends.push_back({"Galkovskyi", "Viacheslav", 380721234567, "fagot@mail.ru"});
    my_friends.push_back({"Rubin", "Vladimir", 79528444832, "ruba@mail.ru"});
    my_friends.push_back({"Prozorov", "Sergei", 4520907661, "sergei.prozorov@gmail.com"});
    my_friends.push_back({"Thatraveler", "Travis", 16615493014, "thatraveler@gmail.com"});

    for (auto const & frnd : my_friends)
        cout << setw(14) << frnd.last_name << setw(11) << frnd.first_name << setw(13) << frnd.tel << setw(26) << frnd.email << endl;
    
    return 0;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
