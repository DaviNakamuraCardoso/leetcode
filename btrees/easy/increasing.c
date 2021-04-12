#include <stdio.h>
#include <stdlib.h>


struct TreeNode
{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;

};

struct TreeNode* copyTree(struct TreeNode* n)
{
    struct TreeNode* new;
    new = malloc(sizeof(struct TreeNode));
    new->val = n->val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void add_queue(struct TreeNode** root, struct TreeNode *new)
{
    if (new == NULL)
    {
        return;
    }

    struct TreeNode** tracer = root;
    struct TreeNode* copy = copyTree(new);

    while ((*tracer) != NULL && ((*tracer)->val - copy->val) < 0)
    {
        tracer = &(*tracer)->left;
    }

    copy->left = *tracer;
    copy->right = NULL;
    *tracer = copy;

    add_queue(root, new->left);
    add_queue(root, new->right);

    return;
}


struct TreeNode* increasingBST(struct TreeNode* root)
{
    struct TreeNode* new = NULL;
    add_queue(&new, root);
    new->right = NULL;

    return new;
}

void print_node(struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%i\n", root->val);
    if (root->right == NULL)
    {
        printf("NULL\n");
    }
    print_node(root->left);
    return;
}

int main(void)
{
    struct TreeNode a = {9, NULL, NULL};
    struct TreeNode b = {7, NULL, NULL};
    struct TreeNode c = {8, &b, &a};
    struct TreeNode d = {6, &c, NULL};
    struct TreeNode e = {1, NULL, NULL};
    struct TreeNode f = {2, &e, NULL};
    struct TreeNode g = {4, NULL, NULL};
    struct TreeNode h = {3, &g, &f};
    struct TreeNode i = {5, &d, &h};

    struct TreeNode* t = increasingBST(&i);

    print_node(t);

    return 0;

}
