#include <stdio.h>

unsigned int str_cmp(char* s1, char* s2)
{
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        int ascii1, ascii2;
        ascii1 = (int) s1[i];
        ascii2 = (int) s2[i];

        if (ascii1 != ascii2)
        {
            return 0;
        }
    }
    return 1;
}

int len(char* str)
{
    int l = 0;
    for (; str[l] != '\0'; l++)
    {
    }

    return l;

}

int str_str(char* haystack, char* needle)
{
    int i, len1, len2;

    len1 = len(haystack);
    len2 = len(needle);

    for (i = 0; i <= len1 - len2; i++)
    {
        if (str_cmp(haystack+i, needle))
        {
            return (i);
        }
    }
    return -1;
}



int main(void)
{

    char hello[] = "";
    char ll[] = "";

    int s = str_str(hello, ll);

    printf("%i\n", s);
    return 0;

}
