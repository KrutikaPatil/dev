#include "heap.hpp"
#include "malloc.h"

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

heap::heap(int size){
    this->data = (int*) malloc(sizeof(int) * size);
    this->size = size;
    this->filled = 0;
}

int heap::pop(){
    int result = this->peek();

    int index = 0;
    int left, right;
    while (true)
    {
        this->children(index, left, right);

        if (right < 0 & left < 0) break;

        if (right < 0){
            swap(this->data[left], this->data[index]);
            index = left;
        } 
        else if(left < 0){
            swap(this->data[right], this->data[index]);
            index = right;
        } 
        else if(this->data[right] < this->data[left]){
            swap(this->data[right], this->data[index]);
            index = right;
        } 
        else{
            swap(this->data[left], this->data[index]);
            index = left;
        }
    }

    if (index != this->filled - 1){
        swap(this->data[index], this->data[this->filled - 1]);
        this->trickle(index);
    }
    this->filled--;

    return result;
} 

void heap::trickle(int index){
    while (true)
    {
        int parent = this->parent(index);
        if (parent >= 0){
            if (this->data[parent] > this->data[index]){
                swap(this->data[parent], this->data[index]);
                index = parent;
            }
            else break;
        }
        else break;
    }
}

int heap::peek(){
    if (this->filled == 0) throw EMPTY_HEAP;

    return this->data[0];
}

bool heap::empty(){
    return this->filled == 0;
}

int heap::parent(int index){
    if (index > 0) return (index - 1) / 2;
    else  return -1;
}

void heap::children(int index, int& left, int& right){
        left = 2 * index + 1;
        right = 2 * index + 2;
        left = left >= this->filled ? -1: left;
        right = right >= this->filled ? -1: right;          
}

void heap::insert(int val){
    if (nullptr == this->data) throw EMPTY_HEAP;

    if (this->filled == this->size) throw FULL_HEAP;
    
    this->data[this->filled] = val;
    this->trickle(this->filled);

    this->filled++;
}

void heap::print(const char* msg){
    fprintf(stdout, "%s start: | ", msg);
    for (size_t i = 0; i < this->filled; i++)
    {
        fprintf(stdout, "%d | ", this->data[i]);
    }
    fprintf(stdout, ":end\n");
}