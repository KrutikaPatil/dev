#ifndef TRIE_H
#define TRIE_H

#include "string"
#include "vector"

class Directory{
    public:
    Directory();
    void cd(const std::string);
    void mkdir(const std::string);
    void rm(const std::string);
    std::string pwd();
    std::vector<std::string> ls();
};

#endif
