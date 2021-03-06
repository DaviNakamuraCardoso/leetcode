/**
 * Leetcode no 1769
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char * boxes, int* returnSize){
     int box_total, count, *ret, i, j, passed, passed_total; 
    
    count = 0; 
    passed = 0;
    passed_total = 0; 
    
    box_total = 0; 
    for (i = 0; boxes[i] != '\0'; i++)
    {
        if (boxes[i] == '1'){
            box_total += i;
            count++;
        }
    }
    
    ret = malloc((i) * sizeof(int)); 
    *returnSize = i; 
    
    for (j = 0; boxes[j] != '\0'; j++)
    {
        if (boxes[j] == '1')
        {
            passed++; 
            passed_total += j; 
            box_total -= j;
        }
        ret[j] = (box_total - (j * (count - passed))) + 
            ((j*passed) - (passed_total)); 
    }
             
    return ret; 
    
    
}
