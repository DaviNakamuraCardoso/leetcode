#include <stdio.h>
#include <stdlib.h>


int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numsSize;

    // Return the matrix itself if the operation is not possible
    if ((*numsColSize) * (numsSize) != (r * c))
    {
        *returnColumnSizes = numsColSize;
        return nums;
    }

    // Else, perform the resizing
    int** matrix = malloc(sizeof(int*) * r);

    int i, j, counter, row, column;

    *returnColumnSizes = malloc(sizeof(int) * r);
    counter = 0;
    for (i = 0; i < r; i++)
    {
        int* col = malloc(sizeof(int) * c);
        for (j = 0; j < c; j++)
        {
            row = counter / (*numsColSize);
            column = counter % (*numsColSize);
            col[j] = nums[row][column];
            counter++;
        }
        (*returnColumnSizes)[i] = c;
        matrix[i] = col;

    }
    *returnSize = r;

    return matrix;
}


int main(void)
{
    int** resizedM;
    int a1[] = {1, 2};
    int b1[] = {3, 4};
    int* m[] = {a1,b1};

    int a = 2;
    int r;
    int* cs;
    resizedM = matrixReshape(m, 2, &a, 4, 1, &r, &cs);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%i", resizedM[i][j]);
        }
        printf("\n");
    }

    return 0;
}
