#include <stdio.h>
#include <stdlib.h>

char* defang_ip_address(char* address){
    int i, j;
    char* new; 
    new = malloc(30*sizeof(char)); 
   
    for (i = 0, j = 0; address[i] != '\0'; i++, j++)
    {
        if (address[i] == '.')
        {
            new[j] = '[';
            new[j+1] = '.';
            new[j+2] = ']';
            j += 2;
        }
        else
        {
            new[j] = address[i];
        }


    }
    new[j] = '\0'; 
    return new;

}

int main(void){

    char t[] = "1.1.1.1"; 
    char* a = defang_ip_address(t); 
    printf("%s\n", a); 

    return 0; 

}
