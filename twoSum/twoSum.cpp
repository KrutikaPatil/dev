#include <malloc.h>
#include "../sort/merge.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int *sortedIndices = merge_sort(numsSize, nums);

    int left = 0;
    int right = numsSize - 1;

    while (true)
    {
        if (nums[sortedIndices[left]] + nums[sortedIndices[right]] == target)
        {
            int *result = (int *)malloc(sizeof(int) * 2);
            result[0] = sortedIndices[left];
            result[1] = sortedIndices[right];
            return result;
        }
        else if (nums[sortedIndices[left]] + nums[sortedIndices[right]] > target)
        {
            right--;
        }
        else if (nums[sortedIndices[left]] + nums[sortedIndices[right]] < target)
        {
            left++;
        }
        if (left == right)
        {
            return nullptr;
        }
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    //  int numbers[4] = {-2, 7, 11, 15};
    int numbers[3] = {3, 2, 4};
    int *result;

    result = twoSum(numbers, 3, 6, result);
    fprintf(stdout, "indices: %d and %d\nnumbers: %d and %d\n",
            result[0], result[1], numbers[result[0]], numbers[result[1]]);

    return 0;
}
