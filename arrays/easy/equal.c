#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b)
{
    int na, nb; 

    na = *(int*)a; 
    nb = *(int*)b; 

    return (na-nb); 
}

unsigned int equal(int* target, int targetSize, int* arr, int arrSize)
{
    int i; 
    if (targetSize != arrSize)
    {
        return 0; 
    }
    qsort(target, targetSize, sizeof(int), compare); 
    qsort(arr, arrSize, sizeof(int), compare); 

    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] != target[i])
            return 0; 
    } 

    return 1; 
}

int main(void)
{
    int size; 

    size = 6; 
    int a[] = {1, 2, 3, 4, 2, 4}; 
    int b[] = {2, 4, 1, 3, 4, 2}; 

    unsigned int is_equal = equal(a, size, b, size); 
    printf("%i\n", is_equal);  

    return 0; 

}
