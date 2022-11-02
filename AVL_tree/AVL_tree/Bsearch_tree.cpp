#include "Bsearch_tree.h"
#include "business.h"
#include <fstream>

Bsearch_tree::Bsearch_tree(string license,int numb)
{
	Tree_element* el = new Tree_element(license, numb);
	root = el;
	size = 1;
}
Bsearch_tree::Bsearch_tree()
{
	root = nullptr;
	size = 0;
}
void Bsearch_tree::delete_tree(Tree_element* el)
{
	if (el)
	{
		delete_tree(el->left);
		delete_tree(el->right);
		delete el;
	}
}
Bsearch_tree::~Bsearch_tree()
{
	delete_tree(root);
}
void Bsearch_tree::print_tree()
{
	if (size == 1)
		cout << root->license << " " << root->number;
	else
		rec_print_tree(root,0);
	cout << endl;
}
void Bsearch_tree::rec_print_tree(Tree_element* el, int space = 0)
{
	if (el)
	{
		if (el->right != nullptr)
			rec_print_tree(el->right, space + 1);
		for (int i = 0; i < space; i++)
			cout << "    ";
		cout << el->license << endl;
		if (el->left != nullptr)
			rec_print_tree(el->left, space + 1);
	}
}
Tree_element* Bsearch_tree::find(string key)
{
	Tree_element* el = root;
	while (el && el->license != key)
	{
		if (el->license == key)
		{
			return el;
		}
		else if (el->license > key)
			el = el->left;
		else
			el = el->right;
	}
	if (el->license == key)
	{
		return el;
	}
	return nullptr;
}
void Bsearch_tree::insert(string license, int number)
{
	Tree_element* el = root;
	while (el && el->license != license)
	{
		if (el->license > license && el->left == nullptr)
		{
			el->left = new Tree_element(license,number);
			++size;
			return;
		}
		if (el->license < license && el->right == nullptr)
		{
			el->right = new Tree_element(license, number);
			++size;
			return;
		}
		if (el->license > license)
			el = el->left;
		else
			el = el->right;
	}
}
bool Bsearch_tree::erase(string key)
{
	Tree_element* el = root;
	Tree_element* parent = nullptr;
	while (el && el->license != key)
	{
		parent = el;
		if (el->license > key)
		{
			el = el->left;
		}
		else
		{
			el = el->right;
		}
	}
	if (!el)
		return false;
	if (el->left == nullptr)
	{
		if (parent && parent->left == el)
			parent->left = el->right;
		if (parent && parent->right == el)
			parent->right = el->right;
		--size;
		delete el;
		return true;
	}
	if (el->right == nullptr)
	{
		if (parent && parent->left == el)
			parent->left = el->left;
		if (parent && parent->right == el)
			parent->right = el->left;
		--size;
		delete el;
		return true;
	}
	Tree_element* replace = el->right;
	while (replace->left)
		replace = replace->left;
	string replace_data = replace->license;
	int replace_number = replace->number;
	erase(replace_data);
	el->license = replace_data;
	el->number = replace_number;
	return true;
}
bool Bsearch_tree::build_tree(string fileName)
{
	ifstream fb;
	fb.open(fileName + ".dat", ios::in | ios::binary);
	if (!fb.good())
	{
		return false;
	}
	business st;
	fb.read((char*)&st, sizeof(business));
	root = new Tree_element(st.license, 0);
	size++;
	fb.read((char*)&st, sizeof(business));
	while (fb.good())
	{
		insert(st.license, size);
		fb.read((char*)&st, sizeof(business));
	}
	return true;
}