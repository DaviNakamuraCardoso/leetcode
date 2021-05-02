/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void get_depth(struct TreeNode* root, int depth, int* d)
{
    if (root == NULL)
        return;
    
    if (depth > (*d)) 
        *d = depth;
    
    get_depth(root->left, depth+1, d); 
    get_depth(root->right, depth+1, d); 
    
    return; 
    
}

void get_sum(struct TreeNode* root, int depth, int max_depth, int* sum)
{
    if (root == NULL)
    {
        return;
    }
    if (depth == max_depth)
        *sum = (*sum) + root->val; 
    
    get_sum(root->left, depth+1, max_depth, sum); 
    get_sum(root->right, depth+1, max_depth, sum); 
    
   
}

int deepestLeavesSum(struct TreeNode* root){
    int tree_depth, max_depth;  
    
    tree_depth = 0; 
    max_depth = 0;  
    
    get_depth(root, 0, &tree_depth); 
    get_sum(root, 0, tree_depth, &max_depth);  
    
    return max_depth;  
 }
