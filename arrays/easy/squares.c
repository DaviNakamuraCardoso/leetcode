#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *ret;
    int i, n, comp, sq1, sq2, index;

    *returnSize = numsSize;

    ret = malloc(numsSize * sizeof(int));

    for (i = 0; i < (numsSize / 2); i++)
    {
        n = nums[i];
        comp = nums[numsSize-i-1];

        sq1 = n*n;
        sq2 = comp*comp;

        index = numsSize-(2*i)-1;
        if (sq1 > sq2)
        {
           ret[index] = sq1;
           ret[index-1] = sq2;
            continue;
        }
        ret[index] = sq2;
        ret[index-1] = sq1;
    }

    return ret;
}

int main(void)
{
    int n, i, size;

    size = 7;
    int nums[] = {-8, -4, -1, 0, 3, 10, 20};

    int* result = sortedSquares(nums, size, &n) ;

    for (i = 0; i < n; i++)
    {

        printf("%i,", result[i]);
    }

    printf("\n");

    free(result);

    return 0;


}
