void traverse(struct TreeNode *root, int **leafVal, int *leafDim) {
    if (!root->left && !root->right) {
        *leafVal = (int *) realloc(*leafVal, (*leafDim+1)*sizeof(int));
        *leafDim = *leafDim+1;
        (*leafVal)[*leafDim-1] = root->val;
        return;
    }

    if (root->left) traverse(root->left, leafVal, leafDim);
    if (root->right) traverse(root->right, leafVal, leafDim);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int *res1=NULL, dim1=0;
    int *res2=NULL, dim2=0;
    bool res=true;

    traverse(root1, &res1, &dim1);
    traverse(root2, &res2, &dim2);
    if (dim1!=dim2) return false;

    for (int i=0; i<dim1; i++) {
        res = res && (res1[i]==res2[i]);
    }
    return res;
}