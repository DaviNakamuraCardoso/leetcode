#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int* arr, int len)
{
    int max_val, i;
    max_val = arr[0];

    for (i = 0; i < len; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    return max_val;

}

bool* kids_with_candies(int* candies, int candiesSize,
    int extraCandies, int* returnSize)
{
    bool* r = malloc(candiesSize*sizeof(bool));
    int i, val;
    val = max(candies, candiesSize);

    for (i = 0; i < candiesSize; i++)
    {
        r[i] = false;
        if (candies[i] >= val - extraCandies)
        {
            r[i] = true;
        }
    }

    return r;
}

int main(void)
{
    int candies[3] = {12, 1, 12};
    int max, i;
    bool* b = kids_with_candies(candies, 3, 10, &max);

    for (i = 0; i < 3; i++)
    {
        printf("%i", b[i]);
    }
    printf("\n");

    free(b);

    return 0;
}
