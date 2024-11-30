int longestZigZagRec(struct TreeNode *root, int *lengths, int max) {
    if (!root) {
        lengths[0] = 0;
        lengths[1] = 0;
        return 0;
    }
    int leftPath, leftMax, rightPath, rightMax;

    leftMax = longestZigZagRec(root->left, lengths, max);
    max = leftMax>max ? leftMax : max;
    leftPath = 1+lengths[1];
    max = leftPath>max ? leftPath : max;

    rightMax = longestZigZagRec(root->right, lengths, leftMax);
    max = rightMax>max ? rightMax : max;
    rightPath = 1+lengths[0];
    max = rightPath>max ? rightPath : max;

    lengths[0] = leftPath;
    lengths[1] = rightPath;
    return max;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestZigZag(struct TreeNode* root) {
    int lengths[2] = {0, 0};
    return longestZigZagRec(root, lengths, 0)-1;
}
