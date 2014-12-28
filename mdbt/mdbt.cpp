#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if(root->left == NULL)
        {
            return 1 + minDepth(root->right);
        }
        else if (root->right == NULL)
        {
            return 1 + minDepth(root->left);
        }
        else
        {
            int min_left = minDepth(root->left) + 1;
            int min_right = minDepth(root->right) + 1;
            return min_left < min_right? min_left : min_right;
        }
    }
};
