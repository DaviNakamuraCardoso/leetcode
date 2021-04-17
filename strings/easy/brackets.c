#include <stdio.h>
#include <stdlib.h>

typedef enum bracket {BR, CR, SQ} BRACKET;

typedef struct _node {
    BRACKET type;
    struct _node* next;
} NODE;


BRACKET bracket_type(char c)
{
    switch (c)
    {
        case '{':
        case '}':
            return CR;
        case '(':
        case ')':
            return BR;

    }
    return SQ;
}


unsigned int close_bracket(char c)
{
    switch (c)
    {
        case '{':
        case '(':
        case '[':
        {
            return 0;
        }
    }
    return 1;
}


NODE* init(char c)
{
    NODE* n;
    n = malloc(sizeof(NODE));

    n->next = NULL;
    n->type = bracket_type(c);

    return n;
}


void push(NODE* n, NODE** root)
{
    n->next = *root;
    *root = n;
}


char pop(NODE** root)
{
    char c = (*root)->type;

    NODE* tmp;
    tmp = (*root)->next;
    free(*root);
    *root = tmp;


    return c;

}

void release(NODE* root)
{
    NODE* tmp;
    NODE* current = root;
    while (current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    return;
}

unsigned int isValid(char * s){

    int i;

    NODE* root = NULL;

    for (i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        printf("Analizing %c\n", c);
        if (!close_bracket(c))
        {

            printf("Is not a close bracket\n");
            NODE* n = init(c);
            push(n, &root);
        }
        else
        {
            BRACKET ch = pop(&root);
            if (bracket_type(c) != ch)
            {
                return 0;
            }
        }
    }
    if ((root) == NULL)
    {
        return 1;
    }


    release(root); 
    return 0;

}


int main(void)
{
    char* s = "({[})";

    printf("%i\n", isValid(s));

    return 0;
}
