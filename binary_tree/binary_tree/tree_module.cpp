#include "btree.h"
#include <iostream>
#include <stack>
#include <list>
#include <string>
using namespace std;

/*btree* create_node(char c)
{
	btree* node = new btree;
	node->element = c;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}*/
bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else return false;
}

btree* create_tree(string postfix)
{
	int n = postfix.length();
	if (n == 0) {
		return nullptr;
	}
	string buf = "";
	stack <btree*> stack_tree;
	for (int i = 0; i < n; i++)
	{
		if (is_operator(postfix[i]))
		{
			btree* rtree = stack_tree.top();
			stack_tree.pop();
			btree* ltree = stack_tree.top();
			stack_tree.pop();
			btree* node = new btree(postfix[i], ltree, rtree);
			stack_tree.push(node);
		}
		else
		{
			stack_tree.push(new btree(postfix[i]));
		}
	}
	return stack_tree.top();
}

void alternate_print(btree* tree)  //debug output
{
	stack <char> alternate_order;
	list <btree*> queue;
	queue.push_back(tree);
	btree* curr = nullptr;
	while (queue.size() != 0)
	{
		curr = queue.front();
		queue.pop_front();
		alternate_order.push(curr->element);
		if (curr->right) 
		{
			queue.push_back(curr->right);
		}

		if (curr->left) 
		{
			queue.push_back(curr->left);
		}
	}
	while (!alternate_order.empty())
	{
		cout << alternate_order.top() << " ";
		alternate_order.pop();
	}
}
void print_tree(btree* tree,int space=0)
{
	if (tree)
	{
		print_tree(tree->left,space+1);		
		for (int i = 0; i < space; i++)
			cout << "  ";
		cout << tree->element << endl;
		print_tree(tree->right, space + 1);
	}

}
void postorder(btree* root)
{
	if (root == nullptr) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->element;
}
void inorder(btree* root)
{
	if (root == nullptr) {
		return;
	}
	if (is_operator(root->element)) {
		cout << "(";
	}
	inorder(root->left);
	cout << root->element;
	inorder(root->right);
	if (is_operator(root->element)) {
		cout << ")";
	}
}