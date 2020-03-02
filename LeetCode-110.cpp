/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int Depth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    if(l == -1 || r == -1 || abs(l - r) > 1) return -1;
    return(l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return Depth(root) >= 0;
}
