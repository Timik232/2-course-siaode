#include "AVL_tree.h"

AVL_tree::AVL_tree()
{
	root = nullptr;
}
AVL_tree::AVL_tree(string license, int numb)
{
	AVL_element* el = new AVL_element(license, numb);
	root = el;
}
void AVL_tree::delete_tree(AVL_element* el)
{
	if (el)
	{
		delete_tree(el->left);
		delete_tree(el->right);
		delete el;
	}
}
AVL_tree::~AVL_tree()
{
	delete_tree(root);
}
void AVL_tree::rec_print_tree(AVL_element* el, int space)
{
	if (el)
	{
		rec_print_tree(el->right, space + 1);
		for (int i = 0; i < space; i++)
			cout << "    ";
		cout << el->license << endl;
		rec_print_tree(el->left, space + 1);
	}
}
void AVL_tree::print_tree()
{
	rec_print_tree(root);
	cout << endl;
}
AVL_element* AVL_tree::rotate_right(AVL_element* el)
{
	AVL_element* left_el = el->left;
	el->left = left_el->right;
	left_el->right = el;
	el->fix_height();
	left_el->fix_height();
	return left_el;
}
AVL_element* AVL_tree::rotate_left(AVL_element* el)
{
	AVL_element* right_el = el->right;
	el->right = right_el->left;
	right_el->left = el;
	el->fix_height();
	right_el->fix_height();
	return right_el;
}
AVL_element* AVL_tree::balance(AVL_element* el)
{
	//cout << el->license << " " << el->get_height() << " ";
	//el->fix_height();
	//cout << el->get_height() << endl;
	if (el->bal_factor() == 2)
	{
		if (el->right->bal_factor() < 0)
			el->right = rotate_right(el->right);
		return rotate_left(el);
	}
	if (el->bal_factor() == -2)
	{
		if (el->left->bal_factor() > 0)
			el->left = rotate_left(el->left);
		return rotate_right(el);
	}
	return el; 
}
AVL_element* AVL_tree::insert_rec(AVL_element* el, string license, int numb)
{
	if (!el) 
		return new AVL_element(license,numb);
	if (license < el->license)
		el->left = insert_rec(el->left,license,numb);
	else
		el->right = insert_rec(el->right,license,numb);
	//print_tree();
	//cout << "***" << endl;
	return balance(el);
}
void AVL_tree::insert(string license, int numb)
{
	root = insert_rec(root, license, numb);
	//print_tree();
	//cout << "-------" << endl;
}
bool AVL_tree::build_tree(string file_name)
{
	ifstream fb;
	this->file_name = file_name;
	fb.open(file_name + ".dat", ios::in | ios::binary);
	if (!fb.good())
	{
		return false;
	}
	business st;
	int count = 0;
	fb.read((char*)&st, sizeof(business));
	root = new AVL_element(st.license, count);
	count++;
	AVL_element* el = root;
	fb.read((char*)&st, sizeof(business));
	while (fb.good())
	{
		insert(st.license, count);
		count+=1;
		fb.read((char*)&st, sizeof(business));
	}
	return true;
}
AVL_element* AVL_tree::find_min(AVL_element* el)
{
	if (el->left)
		return find_min(el->left);
	else return el;
}
AVL_element* AVL_tree::remove_min(AVL_element* el)
{
	if (el->left == nullptr)
		return el->right;
	el->left = remove_min(el->left);
	return balance(el);
}
AVL_element* AVL_tree::erase_rec(AVL_element* el, string key)
{
	if (!el) return nullptr;
	if (key < el->license)
		el->left = erase_rec(el->left, key);
	else if (key > el->license)
		el->right = erase_rec(el->right, key);
	else if (key == el->license)
	{
		AVL_element* left = el->left;
		AVL_element* right = el->right;
		binar_file bin = binar_file();
		bin.delete_by_index(file_name,el->number);
		delete el;
		if (!right) 
			return left;
		AVL_element* min = find_min(right);
		min->right = remove_min(right);
		min->left = left;
		return balance(min);
	}
	return balance(el);
}
void AVL_tree::set_file_name(string name)
{
	this->file_name = name;
}
string AVL_tree::get_file_name()
{
	return file_name;
}
bool AVL_tree::erase(string key)
{
	if (!erase_rec(root, key))
		return false;
	else
		return true;
}