// 1, 3, 5, 7
// LeetCode problem no 1551
int op(int n)
{
    return (2 * n + 1);
}

int minOperations(int n){
    int i, middle, max, ops; 
    middle = 0; 
    
    ops = 0; 
    
    if (n % 2 == 0)
        middle = (op(n / 2) + op(n / 2 - 1))  / 2;
    else 
        middle = n; 
    
    max = op(n-1); 
    for (i = 0; i < (n/2) ; i++)
    {
        max = op(n-i-1); 
        ops += max - middle; 
    }
    
    return ops; 
    
        
}
