#ifndef BINTREE_H
#define BINTREE_H


class binaryNode{
public:
    int value;
    class binaryNode* left;
    class binaryNode* right;

    binaryNode();
    binaryNode(int);
};


class binaryTree{
public:
    class binaryNode* root = nullptr;
    void insert(int);
    bool search(int);
    bool remove(int);

    binaryTree();
};

#endif
