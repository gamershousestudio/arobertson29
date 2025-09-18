#include<iostream>

#include<string>

#include<map>

int main()
{
    using std::cin;
    using std::cout;

    std::map<std::string, std::string> login_info;

    login_info["admin"] = "hello1234";

    cout << login_info[0] << std::endl;

    return 0;
}