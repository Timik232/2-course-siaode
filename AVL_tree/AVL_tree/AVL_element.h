#ifndef __AVL_ELEMENT_H__
#define __AVL_ELEMENT_H__
using namespace std;
#include <iostream>
class AVL_element
{
private:
	unsigned int height;
public:
	string license; //key
	int number;
	AVL_element* left;
	AVL_element* right;
	AVL_element(string license, int numb);
	int get_height();
	int bal_factor();
	void fix_height();
};
#endif