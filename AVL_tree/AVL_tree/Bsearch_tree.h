#ifndef __BSEARCH_TREE_H__
#define __BSEARCH_TREE_H__
using namespace std;
#include "Tree_element.h"
#include <iostream>
#include "business.h"
class Bsearch_tree
{
private:
	string file_name;
	int size;
	Tree_element* root;
	void delete_tree(Tree_element* el);
	void rec_print_tree(Tree_element* el, int space);
public:
	Bsearch_tree(string license, int number);
	Bsearch_tree();
	~Bsearch_tree();
	void set_file_name(string file_name);
	string get_file_name();
	void print_tree();
	business find(string key);
	void insert(string license, int number);
	bool erase(string key);
	bool build_tree(string fileName);
};
#endif
