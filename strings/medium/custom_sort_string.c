int hash[26] = {0};

int ascii(char c)
{
    int a; 
    a = (int) c; 
    return (a - 97);
}

int compare(const void* a, const void* b)
{
    char ca, cb; 
    
    ca = *(char*)a;
    cb = *(char*)b; 
    
    return (hash[ascii(ca)] - hash[ascii(cb)]); 
}

char * customSortString(char * S, char * T){
    int i, j; 
    
    for (i = 0; S[i] != '\0'; i++)
    {
       hash[ascii(S[i])] = i; 
    }
    
    for (j = 0; T[j] != '\0'; j++)
    {
    }
    
    qsort(T, j, sizeof(char), compare); 
    
    return T; 

}

