/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buffer) {
    if (root == NULL) return 0;
    len += sprintf(buffer + len, "%d", root->val);
    buffer[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buffer);
        return 1;
    }
    len += sprintf(buffer + len, "->"); 
    int cnt = getResult(root->left, len, k, ret, buffer);
    cnt += getResult(root->right, len, k + cnt, ret, buffer);
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buffer = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buffer);
    *returnSize = pathCnt;
    return ret;
}
