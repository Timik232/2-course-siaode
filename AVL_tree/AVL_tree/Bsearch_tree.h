#ifndef __BSEARCH_TREE_H__
#define __BSEARCH_TREE_H__
using namespace std;
#include "Tree_element.h"
#include <iostream>
class Bsearch_tree
{
private:
	int size;
	Tree_element* root;
	void delete_tree(Tree_element* el);
	void rec_print_tree(Tree_element* el, int space);
public:
	Bsearch_tree(string license, int number);
	Bsearch_tree();
	~Bsearch_tree();
	void print_tree();
	Tree_element* find(string key);
	void insert(string license, int number);
	bool erase(string key);
	bool build_tree(string fileName);
};
#endif
