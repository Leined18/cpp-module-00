#include "Account.hpp"

int	main(void)
{
	int		x;
	string	Name;
	string line;

	cout << "Introduce your Name: ";
	cin >> Name;
	cout << "Introduce your initial balance: ";
	cin >> x;
	Account acc(Name, x);
	acc.show_info();
	return (0);
}
