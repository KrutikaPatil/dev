#ifndef TRIE_H
#define TRIE_H

#include "string"
#include "vector"

class Node{
    public:
    Node(); // Constructor with no input argument
    Node(std::string ); // Constructor with name
    // address
    Node* ptr;
    // parent
    Node* parent;
    // list of children
    std::vector<class Node*> list_children;
    //
    // syntax for default constructor for a node in cpp
    // 
    // 
};

class Directory{
    public:
    Directory();
    void cd(const std::string);
    void mkdir(const std::string);
    void rm(const std::string);
    std::string pwd();
    std::vector<std::string> ls();


};



/*
class Trie{
    public:
    Trie();
    void add_new_word(const std::string);
    void delete_word(const std::string);
    void rm(const std::string);
    std::string pwd();
    std::vector<std::string> ls();
};
*/


#endif
