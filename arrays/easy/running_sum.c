#include <stdio.h>
#include <stdlib.h>


int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int i;
    *returnSize = numsSize;

    for (i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i-1];
    }

    return nums;
}


int main(void)
{
    int finalSize, i, size;
    size = 3;
    int a[] = {2, 4, 6};
    int* r = runningSum(a, size, &finalSize);

    for (i = 0; i < finalSize; i++)
    {
        printf("%i,", r[i]);
    }
    printf("\n");

    return 0;
}
