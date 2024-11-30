/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root==NULL)
        return 0;
    
    int depthLeft = maxDepth(root->left);
    int depthRight = maxDepth(root->right);
    return depthLeft>=depthRight ? 1+depthLeft : 1+depthRight;
}