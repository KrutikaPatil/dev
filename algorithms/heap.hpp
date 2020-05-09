#ifndef HEAP_H
#define HEAP_H

#define EMPTY_HEAP 1
#define FULL_HEAP 2

class heap{
public:
    int* data = nullptr;
    int size = 0;
    int filled = 0;

    heap(int size);
    heap(int arrSize, int* arr);

    void insert(int val);
    int peek();
    int pop();
    void print(const char* msg = "");
    bool empty();

private:
    void children(int index, int& left, int& right);
    int parent(int index);
    void trickle(int index);
};

class heap meld(class heap heap1, class heap heap2);

#endif