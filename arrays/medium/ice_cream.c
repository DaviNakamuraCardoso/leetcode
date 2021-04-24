// LeetCode problem no 1833

int compare(const void* a, const void* b)
{
    long na, nb; 
    
    na = *(int*)a;
    nb = *(int*)b; 
    
    return (na-nb); 
}

int maxIceCream(int* costs, int costsSize, int coins){
    long long buys, i, money;
    
    qsort(costs, costsSize, sizeof(int), compare); 
    
    
    buys = 0; 
    money = coins; 
    for (i = 0; i < costsSize; i++)
    {
        money -= costs[i] ; 
        if (money < 0)
            break;
        
        buys++; 
            
        
    }
    return buys; 

}
