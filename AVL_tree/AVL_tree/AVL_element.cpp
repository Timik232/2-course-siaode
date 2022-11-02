#include "AVL_element.h"
AVL_element::AVL_element(string license, int numb)
{
	   left = nullptr;
	   right = nullptr;
	   this->license = license;
	   this->number = numb;
	   this->height = 1;
};
int AVL_element::get_height()
{
	return height;
}
int AVL_element::bal_factor()
{
	unsigned int h1, h2;
	if (right)
		h2 = right->get_height();
	else h2 = 0;
	if (left)
		h1 = left->get_height();
	else h1 = 0;
	return h2 - h1;
}
void AVL_element::fix_height()
{
	unsigned int h1,h2;
	if (left)
		h1 = left->get_height();
	else h1 = 0;
	if (right)
		h2 = right->get_height();
	else h2 = 0;
	if (h1 > h2)
		height = h1+1;
	else height = h2+1;
}