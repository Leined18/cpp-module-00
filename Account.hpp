# ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
using namespace	std;

class Account
{
    int user_balance;
    string user_name;
    private:
    /* data */
    public:
        Account(string name, int initial)
        : user_balance(initial), user_name(name){};
        void    show_info(void)
        {cout << "user balance: "<< user_balance << endl;
         cout << "user_name: "<< user_name << endl;};
        

    Account();
};




#endif