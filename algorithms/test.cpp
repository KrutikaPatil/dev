#include "heap.hpp"
#include "stdio.h"

int main(int argc, char const *argv[])
{
    class heap sorted(4);
    sorted.print();

    sorted.insert(2);
    sorted.print();

    sorted.insert(3);
    sorted.print();
    
    sorted.insert(1);
    sorted.print();
    
    sorted.insert(4);
    sorted.print();

    while (!sorted.empty())
    {
        fprintf(stdout, "%d | ", sorted.pop());
    }
    
    return 0;
}
