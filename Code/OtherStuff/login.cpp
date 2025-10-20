#include<iostream>

#include<string>

#include<map>

int main()
{
    using std::cin;
    using std::cout;

    std::string usernames[] = {};
    std::string passwords[] = {};

    std::string current_user;
    
    std::string admin_password;

    bool exit;

    while(!exit)
    {
        cout << "Welcome!\n";

        if(admin_password == "")
        {
            cout << "You are the admin, please create an admin password:\n";
            cin >> admin_password;
            cout << "\nThank you, here are your login credentials: \nUsername: 'admin' \nPassword '" << admin_password << "'\n";
        }

        char new_account;

        cout << "Would you like to create a new account? (y/n)\n";
        cin >> new_account;

        exit = true;
    }    

    return 0;
}