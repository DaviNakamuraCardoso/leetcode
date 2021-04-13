#include <stdio.h>

unsigned short ascii(char c){
    int a; 
    a = (int) c; 
    
    if (a >= 97)
    {
        return (a - 97 + 26); 
    }
    
    return (a - 65); 
    
}

int numJewelsInStones(char * jewels, char * stones){
    
    int i, j, k, counter; 
    unsigned short is_jewel[52]; 
    
    // All letters are set to false
    for (k = 0; k < 52; k++)
    {
        is_jewel[k] = 0; 
    }
    
    // Loop through the jewels and set the array numbers to true
    for (i = 0; jewels[i] != '\0'; i++)
    {
        is_jewel[ascii(jewels[i])] = 1; 
    }
    
    counter = 0; 
    
    for (j = 0; stones[j] != '\0'; j++)
    {
        if (is_jewel[ascii(stones[j])])
        {
            counter++; 
        }
    }

    return counter; 
}
int main(void)
{
    int jewels; 

    char j[] = "aA"; 
    char s[] = "aAAkdjflafalsdfA"; 
    jewels = numJewelsInStones(j, s); 

    printf("There are %i jewels.\nThe expected result is %i\n", jewels, 6); 
    return 0; 
}
