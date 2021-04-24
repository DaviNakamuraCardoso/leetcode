// LeetCode problem no 1773

typedef struct trie
{
    int count;  
    struct trie* next[26]; 
} TRIE; 


int ascii(char c)
{
    int a; 
    a = (int) c - 97; 
    return (a);  
}

TRIE* init_trie(void)
{
    int i;
   TRIE* t; 
    
    t = malloc(sizeof(TRIE)); 
    
    for (i = 0; i < 26; i++)
    {
        t->next[i] = NULL; 
    }
    t->count = 0; 
    
    return t; 
}

void add_word(TRIE* root, char* word)
{
    TRIE* current; 
    int i, a; 
    
    
    current = root; 
    for (i = 0; word[i] != '\0'; i++)
    {
        a = ascii(word[i]) ; 
        if (current->next[a] == NULL)
        {
            current->next[a] = init_trie();
        }
        current = current->next[a]; 
    }
    current->count++; 
}


int search_trie(TRIE* root, char* word)
{
    TRIE* current; 
    int i; 
    
    current = root; 
    for (i = 0; word[i] != '\0'; i++)
    {
        if (current == NULL)
            return 0;  
        
        current = current->next[ascii(word[i])];
    }
    
    if (current == NULL)
        return 0; 
    return (current->count); 
}


int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
   
    int i, j, count; 
    TRIE *rule1, *rule2, *rule3; 
    
    rule1 = init_trie(); 
    rule2 = init_trie(); 
    rule3 = init_trie(); 
    
    for (i = 0; i < itemsSize; i++)
    {
        add_word(rule1, items[i][0]);  
        add_word(rule2, items[i][1]);
        add_word(rule3, items[i][2]);
          
    }
    
    switch(ruleKey[0])
    {
        case 't': 
           count = search_trie(rule1, ruleValue); 
           break;
        case 'c': 
            count = search_trie(rule2, ruleValue); 
            break;
        default: 
            count = search_trie(rule3, ruleValue); 
            break;
    }
    
    return count; 
        
    
}
