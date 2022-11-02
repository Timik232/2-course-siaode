#ifndef __TREE_ELEMENT_H__
#define __TREE_ELEMENT_H__
#include <iostream>
using namespace std;
struct Tree_element
{
	string license; //key
	int number;
	Tree_element* left;
	Tree_element* right;
	Tree_element(string license, int numb) {
		left = nullptr;
		right = nullptr;
		this->license = license;
		this->number = numb;
	};
};
#endif
