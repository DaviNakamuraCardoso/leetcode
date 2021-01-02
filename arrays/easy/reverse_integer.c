#include <stdio.h>
#include <math.h>


int main(void)
{  
    int x = 21;
    
    /* Check the input and constraints */ 
    if (x < pow(-2, 31) || x > pow(2, 31)-1)
    {
        return (0);
    }

    printf("%i\n", x);

}

/*

int len(int a)
{
    int l = 0;
    for (int i = a; i >= 1; i /= 10)
    {
        l++;
    }

    return (l);

}

int solution(int x)
{
    

}
*/
