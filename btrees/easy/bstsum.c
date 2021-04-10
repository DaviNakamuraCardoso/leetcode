#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };


int rangeSumBst(struct TreeNode* root, int low, int high)
{
    if (root == NULL)
    {
        return 0;
    }

    int val;

    if ((root->val > high) || (root->val < low))
    {
        val = 0;
    }
    else
    {
        val = root->val;
    }

    return val + rangeSumBst(root->left, low, high) + rangeSumBst(root->right, low, high);

}

int main(void)
{
    int sum;
    struct TreeNode e = {3, NULL, NULL};
    struct TreeNode d = {7, NULL, NULL};
    struct TreeNode c = {18, NULL, NULL};
    struct TreeNode b = {15, &c, NULL};
    struct TreeNode a = {5, &e, &d};
    struct TreeNode r = {10, &a, &b};

    sum = rangeSumBst(&r, 7, 15);
    printf("%i\n", sum);
    return 0;
}
