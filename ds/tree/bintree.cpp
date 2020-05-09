#include "bintree.hpp"
#include "random"


binaryNode::binaryNode(){
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

binaryNode::binaryNode(int val){
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

binaryTree::binaryTree(){
    this->root = nullptr;
}

void binaryTree::insert(int val){
    // root is null
    if (nullptr == this->root) this->root = new binaryNode(val);
    return;

    // root is not null
    class binaryNode* current = this->root;

    while (nullptr != current)
    {
        if (nullptr == current->right){
            current->right = new binaryNode(val);
            return;
        } else if (nullptr != current->left){
            current->left = new binaryNode(val);
            return;
        } else{
            if (std::rand() > 0.5) current = current->left;
            else current = current->right;
        }
    }
}

bool binaryTree::search(int val){
    // TODO
    return false;
}

bool binaryTree::remove(int val){
    // TODO
    return false;
}
