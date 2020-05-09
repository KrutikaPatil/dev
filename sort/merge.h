#include "malloc.h"


void dump(int lo, int hi, int* arr, const char* msg, FILE* file = stdout){
    fprintf(file, "%s: ", msg);
    for (size_t i = lo; i <= hi; i++)
    {
        fprintf(file, "%d | ", arr[i]);
    }
    fprintf(stdout, "\n");
}


void _merge(int lo, int mid, int hi, int* arr, int* indices, int* aux){
    int left = lo;
    int right = mid + 1;

    for (size_t i = lo; i <= hi; i++)
    {
        // fprintf(
        //     stdout,
        //     "lo: %d | hi: %d | mid: %d | i: %d | left: %d | right: %d\n",
        //     lo, hi, mid, int(i), left, right
        // );

        // right buffer has been used completely
        if (right > hi){
            aux[i] = indices[left];
            left++;
            continue;
        } 
        
        // left buffer has been used completely
        if (left > mid){
            aux[i] = indices[right];
            right++;
            continue;
        }
        
        if (arr[indices[left]] <= arr[indices[right]]){
            aux[i] = indices[left];
            left++;
        } else{
            aux[i] = indices[right];
            right++;
        }
    }

    for (size_t i = lo; i <= hi; i++){
        indices[i] = aux[i];
    }
}


void _merge_sort(int lo, int hi, int* arr, int* indices, int* aux){
    // everything is memory allocated

    if (hi < lo) {
        return;
    };

    if (hi == lo){
        indices[lo] = lo;
        return;
    }

    // dump(lo, hi, arr, "Before split");

    int mid = int((hi + lo) / 2);

    // fprintf(
    //     stdout,
    //     "lo: %d | hi: %d | mid: %d\n",
    //     lo, hi, mid
    // );
    
    _merge_sort(lo, mid, arr, indices, aux);
    _merge_sort(mid + 1, hi, arr, indices, aux);
    
    // dump(lo, hi, indices, "After split");
    
    _merge(lo, mid, hi, arr, indices, aux);

    // dump(lo, hi, indices, "After merge");
}


int* merge_sort(int arrSize, int* arr){
    if (arrSize < 1) return arr;

    int* indices = (int*) malloc(sizeof(int) * arrSize);
    for (size_t i = 0; i < arrSize; i++)
    {
        indices[i] = i;
    }
    
    int* aux = (int*) malloc(sizeof(int) * arrSize);
    _merge_sort(0, arrSize - 1, arr, indices, aux);
    return indices;
}