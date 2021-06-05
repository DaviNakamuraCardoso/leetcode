
/**
*           # 1161. Maximum level sum of a binary tree
*
*       Given the root of a binary tree, the level of its root is 1,
*       the level of its children is 2, and so on.
*
*       Return the smallest level x such that  the sum  of  all the
*       values of nodes at level x is maximal.
*
*
*/

void sum_level(struct TreeNode* root, int level, int* sums, int* depth)
{
    if (root == NULL) return;

    sums[level] += root->val;

    sum_level(root->right, level+1, sums, depth);
    sum_level(root->left, level+1, sums, depth);

    *depth = (level > *depth) ? level : *depth;

    return;

}

int maxLevelSum(struct TreeNode* root){
    int sums[10001] = {0};
    int max_level, max_value, depth = 0;

    sum_level(root, 0, sums, &depth);

    max_value = sums[0];
    max_level = 0;

    for (int i = 0; i <= depth; i++)
    {
        if (sums[i] > max_value)
        {
            max_level = i;
            max_value = sums[i];
        }
    }



    return max_level+1;



}
