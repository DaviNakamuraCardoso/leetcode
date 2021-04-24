int fact(int n)
{
    if (n <= 0)
        return 0; 
    
        
    return (n * (n-1)) / 2; 
}

int numIdenticalPairs(int* nums, int numsSize){
    int hash[101] = {0}; 
    int i, j, pairs; 
    
    pairs = 0; 
    
    for (i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++; 
    }
    
    for (j = 0; j <= 100; j++)
    {
       pairs += fact(hash[j]); 
    }
    
    return pairs; 
    
}
