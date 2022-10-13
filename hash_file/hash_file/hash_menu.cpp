#include "hash.h"
#include <fstream>
#include "business.h"

void testHeshT()
{
	Hash h(4);
	cout << h.hashFunction('A') << endl;
	HashElement h1(1, "test");
	HashElement h2(2, "nottest");
	HashElement h3(3, "some");
	HashElement h4(4, "somebody");
	HashElement h5(5, "12345do");
	h.insertItem(h1);
	h.insertItem(h2);
	h.insertItem(h3);
	h.insertItem(h4);
	h.insertItem(h5);
	cout << "Before deleting:\n";
	h.displayHash();
	h.deleteItem("test");
	cout << "after deleting:\n";
	h.displayHash();
	cout << "Number of key 'nottest' is " << h.findKey("nottest") << endl;
}
void hash_menu()
{
	cout << "Enter amount of hash-elemnts to generate hash-table\n";
	int n;
	cin >> n;
	Hash H(n);
	cout << "Choose action with hash:\n1.Insert element\n2.Delete element by key\n3.Print hash-table\n4.Find number by key\n5.TestheshT\n6.Exit\n";
	char c;
	while (true)
	{
		cin >> c;
		string line;
		HashElement h1(0, "");
		switch (c)
		{
		case '1':
			cout << "Enter key of element\n";
			line = "";
			cin >> line;
			cout << "Enter number of element\n";
			int numb;
			cin >> numb;
			h1.number = numb;
			h1.license = line;
			H.insertItem(h1);
			cout << "Added\n";
			break;
		case '2':
			cout << "Enter key of element\n";
			line = "";
			cin >> line;
			H.deleteItem(line);
			cout << "Was deleted\n";
			break;
		case '3':
			H.displayHash();
			break;
		case '4':
			cout << "Enter key of element\n";
			line = "";
			cin >> line;
			cout << "Number is " << H.findKey(line) << endl;
			break;
		case '5':
			testHeshT();
			break;
		case '6':
			return;
		default:
			cout << "Invalid input, try again\n";
			break;
		}
	}
}

void file_hash_menu()
{
	cout << "Enter amount of hash-elemnts to generate hash-table\n";
	int n;
	cin >> n;
	Hash H(n);
	cout << "Choose action with hash:\n1.Insert element from file\n2.Delete element by key\n3.Find element by key\n4.Exit\n";
	char c;
	int count = 0;
	while (true)
	{
		cin >> c;
		string name;
		string key;
		int number;
		ifstream in;
		bool isError = false;
		business example;
		if (c == '1')
		{			
			if (!in.is_open())
			{
				cout << "Enter name of text file\n";
				cin >> name;
				in.open(name + ".dat", ios::in || ios::binary);
			}
			if (in.good())
			{
				in.read((char*)&example, sizeof(business));
				HashElement El(count, example.license);
				count += 1;
				H.insertItem(El);
				cout << "HeshElement was added\n";
			}
			else
			{
				cout << "File ended\n";
				in.close();
			}
		}/*
		else if (c == '2')
		{
			cout << "Enter key of element\n";
			cin >> key;
			number = H.findKey(key);
			H.deleteItem(key);
			cout << "Enter name of file to delete element\n";
			cin >> name;
			if (delete_by_key(name, key))
				cout << "Element was deleted\n";
		}
		else if (c == '3')
		{
			cout << "Enter key of element\n";
			cin >> key;
			number = H.findKey(key);
			example = get_by_index(number);
			cout << "Was found:\n" << example.license << " " << example.name << " " << example.founder << " ";
			if (example.isActive)
				cout << "active\n";
			else cout << "not active\n";
		}*/
		else if (c=='4')
			return;
		else
		{
			cout << "Invalid input, try again\n";
		}
	}
}
