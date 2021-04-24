int maxDepth(char * s){
    int depth, i, max; 
    depth = 0; 
    max = 0;
    
    
    for (i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
            case '(': 
                depth++;
                break;
            case ')': 
                depth--;
                break;
            
        }
        max = (depth > max) ? (depth) : max; 
        
    }
    
    return max; 

}
