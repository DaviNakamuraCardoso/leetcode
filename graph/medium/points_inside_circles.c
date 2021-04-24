int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    
    int i, j, *ret, dist, x, y, count, r;
    *returnSize = queriesSize; 
    ret = malloc(queriesSize * sizeof(int));
    
    
    for (i = 0; i < queriesSize; i++)
    {
        int dx, dy; 
        x = queries[i][0]; 
        y = queries[i][1];
        r = queries[i][2];
        count = 0;
        
        for (j = 0; j < pointsSize; j++)
        {
            dx = (x - points[j][0]) * (x - points[j][0]);
            dy = (y - points[j][1]) * (y - points[j][1]);
            dist = dx + dy;
            
            if ((dx + dy) <= (r*r))
            {
                count++; 
            }
        }
        ret[i] = count; 
    }
    
    return ret; 
}
