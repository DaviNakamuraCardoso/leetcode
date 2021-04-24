struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    
    struct ListNode *a_point, *b_point, *head, *l2_tail, *current, *tmp;
    int i, j; 
    
    a_point = list1; 
    
    for (i = 0; i+1 < a; i++)  {
        a_point = a_point->next; 
    }
    
    // Head of the list we will remove
    head = a_point->next; 
    
    b_point = a_point; 
    for (j = i; j <= b; j++) {
        b_point = b_point->next; 
    }
    
    
    l2_tail = list2; 
    while (l2_tail->next != NULL) {
        l2_tail = l2_tail->next; 
    }
    
    
    a_point->next = list2; 
    l2_tail->next = b_point; 
    
    
    // Release the removed list 
    for (; current != NULL; current = tmp) {
        tmp = current->next; 
        free(current); 
    }
    
    return list1; 
        
}
