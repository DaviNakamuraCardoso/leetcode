int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int **reference, i, j, n, inc, tmp; 
    
    reference = malloc(2 * sizeof(int*)); 
    int x[4] = {0}; 
    int y[4] = {0}; 
    reference[0] = x; 
    reference[1] = y; 
    
    
    for (i = 0; i < gridSize; i++)
    {
         
        for (j = 0; j < (*gridColSize); j++)
        {
            n = grid[i][j]; 
            reference[1][i] = (reference[1][i] > n) ? (reference[1][i]) : n;
            reference[0][j] = (reference[0][j] > n) ? (reference[0][j]) : n;
        }
    }
    
    inc = 0;
    
    for (i = 0; i < gridSize; i++)
    {
        for (j = 0; j < (*gridColSize); j++)
        {
            n = grid[i][j]; 
            tmp = (reference[0][j] > reference[1][i]) ? 
                (reference[1][i] - n) : (reference[0][j] - n);
            inc = (tmp > 0) ? (inc + tmp) : inc;
                     
        }
    }
    
    return inc; 

}
