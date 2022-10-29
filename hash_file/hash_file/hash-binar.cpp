#include "binar.cpp"
#include "hash.h"
bool deleting(Hash H, string name, string key)
{
	int number = H.findKey(key);
	H.deleteItem(key);
	if (delete_by_key(name, key))
		return true;
	else return false;
}
