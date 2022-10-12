#ifndef __HASH_H__
#define __HASH_H__
#include <list>
#include <iostream>
using namespace std;
struct HashElement
{
	int number = 0; 
	//char license[8]; //key
	string license = "";
	HashElement(int number, string license)
	{
		this->number = number;
		this->license = license;
	}
};
class Hash 
{
private:
	int amount = 1;
	list <HashElement>* table;
public:
	Hash(int amount = 100);
	void insertItem(HashElement element);
	void deleteItem(string license);
	int hashFunction(unsigned int x) {
		return (x % amount);
	}
	void displayHash();
	int findKey(string license);
};
#endif
