/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _node {
   short index;
    struct _node* next;
} NODE;

void add_queue(NODE** root, short index) {

    NODE* new;

    new = malloc(sizeof(NODE));
    new->index = index;
    new->next = *root;
    *root = new;
    return;
}


int pop(NODE** root) {
    int r;

    NODE* tmp;
    if ((*root) == NULL) {
        return -1;
    }
    r = (*root)->index;

    tmp = *root;
    *root = (*root)->next;

    free(tmp);

    return r;
}


int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    NODE *root_even, *root_odd;
    int i;

    *returnSize = numsSize;
    root_even = NULL;
    root_odd = NULL;

    for (i = 0; i < numsSize; i++) {
       if ((i % 2) != 0) {
           if (nums[i] % 2 == 0) {
              add_queue(&root_even, i);
           }
       }
       else {
           if (nums[i] % 2 != 0) {
               add_queue(&root_odd, i);
           }
       }
    }

    while ((root_odd != NULL) && (root_even != NULL)) {
        int even, odd, tmp;

        even = pop(&root_even);
        odd = pop(&root_odd);

        tmp = nums[even];
        nums[even] = nums[odd];
        nums[odd] = tmp;
    }

    return nums;
}
