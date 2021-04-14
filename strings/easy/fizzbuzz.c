#include <stdio.h>
#include <stdlib.h>

char** fizz_buzz(int n, int* returnSize)
{
    int i, index;
    char** words;

    words = malloc(sizeof(char*) * n);
    *returnSize = n;

    char* fizz = malloc(5*sizeof(char));
    char* buzz = malloc(5*sizeof(char));
    char *fizzbuzz = malloc(9*sizeof(char));


    fizz = "Fizz";
    buzz = "Buzz";
    fizzbuzz = "FizzBuzz";

    for (i = 0; i < n; i++)
    {
        index = i + 1;
        if ((index % 3) == 0 && (index % 5) == 0)
        {
            words[i] = fizzbuzz;
        }
        else if ((index % 3) == 0)
        {
            words[i] = fizz;
        }
        else if ((index % 5) == 0)
        {
            words[i] = buzz;
        }
        else
        {
            char* w = malloc(5*sizeof(char));
            sprintf(w, "%i", index);
            words[i] = w;
        }
    }
    return words;

}


int main(void)
{
    int size, i, rsize;


    size = 15;
    char** a = fizz_buzz(size, &rsize);
    for (i = 0; i < size; i++)
    {
        printf("%s\n", a[i]);
    }

    return 0;

}
