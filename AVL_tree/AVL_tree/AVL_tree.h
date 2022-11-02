#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__
using namespace std;
#include <iostream>
#include "AVL_element.cpp"
#include <fstream>
class AVL_tree
{
private:
	AVL_element* root;
	AVL_element* rotate_left(AVL_element* el);
	AVL_element* rotate_right(AVL_element* el);
	AVL_element* balance(AVL_element* el);
	void delete_tree(AVL_element* el);
	void rec_print_tree(AVL_element* el, int space=0);
	AVL_element* find_min(AVL_element* el);
	AVL_element* remove_min(AVL_element* el);
	AVL_element* erase_rec(AVL_element* el, string key);
	AVL_element* insert_rec(AVL_element* el, string license, int numb);
public:
	AVL_tree();
	AVL_tree(string license, int numb);
	~AVL_tree();
	void insert(string license, int numb);
	bool erase(string key);
	bool build_tree(string file_name);	
	void print_tree();
};
#endif
