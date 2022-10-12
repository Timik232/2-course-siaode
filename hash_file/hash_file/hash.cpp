#include "hash.h"

Hash::Hash(int amount) 
{
	this->amount = amount;
	table = new list<HashElement>[amount];
}
void Hash::insertItem(HashElement element)
{
	unsigned int key = ' ';
	for (int i = 0; i < element.license.length(); i++)
		key += abs(static_cast<int> (element.license[i]));
	int index = hashFunction(key);
	table[index].push_back(element);
}
void Hash::deleteItem(string license)
{
	unsigned int key = ' ';
	for (int i = 0; i < license.length(); i++)
		key += abs(static_cast<int> (license[i]));
	int index = hashFunction(key);
	list <HashElement> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) 
	{
		cout << 1;
		if (i->license == license)
		{
			//i->license = "-1";
			break;
		}
	}
	if (i != table[index].end())
		table[index].erase(i);
}
void Hash::displayHash() 
{
	for (int i = 0; i < amount; i++) {
		cout << i;
		if (!table[i].empty())
		for (auto x : table[i])
		{
			cout << " --> " << x.license;
			/*for (int i = 0; i < 8; i++)
				 cout << x.license[i];*/
		}
		cout << endl;
	}
}
int Hash::findKey(string license)
{
	unsigned int key = ' ';
	for (int i = 0; i < license.length(); i++)
		key += abs(static_cast<int> (license[i]));
	int index = hashFunction(key);
	list <HashElement> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (i->license == license)
		{
			return i->number;
		}
	}
}

