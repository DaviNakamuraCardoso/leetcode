#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    fscanf(stdin, "%i", &a);

    switch (a)
    {
        case a:
        {
            goto hello;
            break;
        }
    }

    hello: {
        printf("Hello, World!\n");
        break;
    }
}
