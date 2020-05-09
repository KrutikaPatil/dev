#include "stdio.h"
#include "vector"

// build max heap: turn array to heap
// heapify: input array, index ..... correct elements a index

void print(int arrSize, int *arr)
{
    fprintf(stdout, "start: ");
    for (size_t i = 0; i < arrSize; i++)
    {
        fprintf(stdout, "| %d ", arr[i]);
    }
    fprintf(stdout, ":end\n");
}

void print(std::vector<int> arr)
{
    int arrSize = arr.size();
    fprintf(stdout, "start: ");
    for (size_t i = 0; i < arrSize; i++)
    {
        fprintf(stdout, "| %d ", arr[i]);
    }
    fprintf(stdout, ":end\n");
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void heapify(int i, int *input_array, int arrSize)
{
    fprintf(stdout, "index: %d\n", i);
    print(arrSize, input_array);

    // edge cases : left or right child is None
    // parent i: left child 2i +1 right child 2i+2

    // left none, right none ---- Done
    // left none, right int ------------------ DNE
    // left int, right none
    // left int, right int --------------- Done

    if (2 * i + 2 >= arrSize)
    {
        if (2 * i + 1 >= arrSize)
            return;
        else
        {
            if (input_array[2 * i + 1] > input_array[i])
            {
                swap(input_array[i], input_array[2 * i + 1]);
                return;
            }
        }
    }
    heapify(2 * i + 2, input_array, arrSize);
    heapify(2 * i + 1, input_array, arrSize);

    if (
        (input_array[i] >= input_array[2 * i + 1]) &
        (input_array[i] >= input_array[2 * i + 2]))
        return;

    else if ((input_array[i] < input_array[2 * i + 1]))
    {
        swap(input_array[i], input_array[2 * i + 1]);
    }
    if ((input_array[i] < input_array[2 * i + 2]))
    {
        swap(input_array[i], input_array[2 * i + 2]);
    }
}

void heapify(int i, std::vector<int> input_array)
{
    fprintf(stdout, "index: %d\n", i);
    print(input_array);

    // edge cases : left or right child is None
    // parent i: left child 2i +1 right child 2i+2

    // left none, right none ---- Done
    // left none, right int ------------------ DNE
    // left int, right none
    // left int, right int --------------- Done

    int arrSize = input_array.size();

    if (2 * i + 2 >= arrSize)
    {
        if (2 * i + 1 >= arrSize)
            return;
        else
        {
            if (input_array[2 * i + 1] > input_array[i])
            {
                swap(input_array[i], input_array[2 * i + 1]);
                return;
            }
        }
    }
    heapify(2 * i + 2, input_array);
    heapify(2 * i + 1, input_array);

    if (
        (input_array[i] >= input_array[2 * i + 1]) &
        (input_array[i] >= input_array[2 * i + 2]))
        return;

    else if ((input_array[i] < input_array[2 * i + 1]))
    {
        swap(input_array[i], input_array[2 * i + 1]);
    }
    if ((input_array[i] < input_array[2 * i + 2]))
    {
        swap(input_array[i], input_array[2 * i + 2]);
    }
}

void build_max_heap(int arrSize, int *input_array)
{
    for (int i = 0; i <= arrSize / 2; i++)
    {
        heapify(i, input_array, arrSize);
        print(arrSize, input_array);
    }
}

void build_max_heap(std::vector<int> input_array)
{
    int arrSize = input_array.size();

    for (int i = 0; i <= arrSize / 2; i++)
    {
        heapify(i, input_array);
        print(input_array);
    }
}

int main(int argc, char const *argv[])
{
    // std::vector<int> arr;
    // arr.emplace_back(1);
    // arr.emplace_back(3);
    // arr.emplace_back(2);
    // arr.emplace_back(4);
    // arr.emplace_back(5);

    int arr[5] = {1, 3, 2, 4, 5};

    print(5, arr);

    //heapify(0, arr, 4);

    build_max_heap(5, arr);

    print(5, arr);

    fprintf(stdout, "%s", "heap is fun!\n");
    return 0;
}
