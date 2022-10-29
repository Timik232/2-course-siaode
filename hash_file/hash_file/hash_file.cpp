#include <iostream>
#include "hash_menu.cpp"
//#include "binar.cpp"

	
int main()
{
	char c;
	while (true)
	{
		cout << "Choose menu to interact with:\n1.Menu to interact with binary file\n2.Menu to interact with hash\n3.Menu to interact with file by hash\n4.Exit\n";
		cin >> c;
		switch (c)
		{
		case '1':
			binar_menu();
			break;
		case '2':
			hash_menu();
			break;
		case '3':
			file_hash_menu();
			break;
		case '4':
			exit(0);
		default:
			cout << "Invalid input, try again\n";
			break;
		}
		
	}
}
