#ifndef __BRTREE_H__
#define __BRTREE_H__
struct btree {
    char element;
    btree* right;
    btree* left;
    btree(char c)
    {
        this->element = c;
        this->right = nullptr;
        this->left = nullptr;
    };
    btree(char c, btree* left, btree* right)
    {
        this->element = c;
        this->right = right;
        this->left = left;
    };
};
#endif
