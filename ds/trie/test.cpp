#include "stdio.h"
#include "trie.hpp"

int main(int argc, char const *argv[])
{
    class Directory dir;
    dir.mkdir("home");
    dir.cd("home");
    dir.mkdir("Desktop");
    dir.mkdir("Downloads");
    dir.pwd();
    dir.cd("Desktop");
    dir.pwd();
    dir.cd("..");
    dir.ls();
    dir.rm("Downloads");
    dir.ls();
    // mkdir home, cd home, mkdir child1, mkdir child2, cd child1, pwd,  ls, rm child2, ls 
    fprintf(stdout, "Done implementing directory structure\n");
    return 0;
}
