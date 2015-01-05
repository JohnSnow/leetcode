#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) {
            return false;
        }

        if(root->left == NULL && root->right == NULL) {
            return sum == root->val?true:false;
        }

        int newSum = sum - root->val;

        if(root->left == NULL) {
            return hasPathSum(root->right, newSum);
        }else if(root->right == NULL) {
            return hasPathSum(root->left, newSum);
        }else{
            return (!hasPathSum(root->left, newSum) && !hasPathSum(root->right, newSum))?false:true;
        }
    }
};
