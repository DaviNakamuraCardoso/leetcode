
/**
*               # 1315. Sum of Nodes with Even-Valued Grandparent
*
*            Given a binary tree, return the sum of values of  nodes
*            with even-valued grandparent.  (A grandparent of a node
*            is the parent of its parent, if it exists.)
*
*            If there are no nodes with an even-valued   grandparent,
*            return 0.
*
*/


void get_gc(struct TreeNode* root, int level, int target, int* sum)
{
    if (root == NULL) return;

    // Grandchild
    if (level == target)
    {
       *sum += root->val;
    }
    else
    {
        get_gc(root->left, level+1, target, sum);
        get_gc(root->right, level+1, target, sum);
    }
    return;
}

void sum_gp(struct TreeNode* root, int* sum)
{
    if (root == NULL) return;
    if (root->val % 2 == 0)
    {
        get_gc(root, 0, 2, sum);
    }

    sum_gp(root->left, sum);
    sum_gp(root->right, sum);
    return;

}


int sumEvenGrandparent(struct TreeNode* root){

    int sum = 0;

    sum_gp(root, &sum);

    return sum;
}
