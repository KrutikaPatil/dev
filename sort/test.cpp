#include "merge.h"


int main(int argc, char const *argv[])
{
    int arr[12] = {2, 3, 5, 1, 8, 4, 2, 7, 5, 2, 6, 0};
    int* indices = merge_sort(12, arr);

    fprintf(stdout, "Sorted array: ");

    for (size_t i = 0; i < 12; i++)
    {
        fprintf(stdout, "%d | ", arr[indices[i]]);
    }
    fprintf(stdout, "\n");
    
    return 0;
}

