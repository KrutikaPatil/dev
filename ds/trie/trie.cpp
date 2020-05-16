#include "trie.hpp"
#include "vector"
#include "string"
#include "stdio.h"
#include "iostream"

Node::Node(){
    parent = NULL;
    name = "";
};

Node::Node(std::string name_){
    name = name_;
    parent = NULL;
};

Directory::Directory(){
    root = new Node();
}

void Directory::mkdir(const std::string dir_name){
    // create new node with input string name
    // add address of new node to the list of addresses of children of the current node
    Node* new_node = new Node(dir_name);
    this->current->list_children.push_back(new_node);
    new_node->parent = this->current;
}

int Directory::cd(const std::string dir_name){
    // get vector of all child dirs
    // loop over all: when dir name is found change current
    std::vector<Node *> all_child_dirs = this->current->list_children;
    for (size_t i = 0; i < all_child_dirs.size(); i++)
    {
        if (all_child_dirs[i]->name==dir_name)
        {
            this->current = all_child_dirs[i];
            return(0);
        }   
    }
    std::cout<<"please check directory name to cd";
    return (1);
}

std::vector<std::string> Directory::ls(){
    std::vector<std::string> list_names;
    std::vector<Node *> all_child_dirs = this->current->list_children;
    for (size_t i = 0; i < all_child_dirs.size(); i++)
    {
        list_names.push_back(all_child_dirs[i]->name);
        std::cout<<all_child_dirs[i]->name<<"\n";    
    }
    return list_names;
}

int Directory::rm(const std::string dir_name){
    // get vector of all child dirs
    // loop over all: when dir name is found change current
    std::vector<Node *> all_child_dirs = this->current->list_children;
    for (size_t i = 0; i < all_child_dirs.size(); i++)
    {
        if (all_child_dirs[i]->name==dir_name)
        {
            this->current->list_children.erase(this->current->list_children.begin() + 1);
            return(0);
        }   
    }
    std::cout<<"please check directory name to cd";
    return (1);
}

std::string Directory::pwd(){
    std::vector<std::string> list_names;
    Node *index = this->current;
    list_names.push_back(index->name);
    while (index->parent != NULL)
    {
        list_names.push_back(index->parent->name);
        index = index->parent;
    }
    std::string output_string = "";
    for (size_t i = 0; i < list_names.size(); i++)
    {
        output_string = output_string + " " + list_names[i];
    }
    return output_string;
}





