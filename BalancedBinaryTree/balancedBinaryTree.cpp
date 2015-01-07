#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;

        int left_depth = 0;
        int right_depth = 0;
        if(!isBalanced(root->left, left_depth) || !isBalanced(root->right, right_depth)) return false;
        left_depth++;
        right_depth++;
        if (left_depth +1 < right_depth || left_depth - 1> right_depth) return false;

        return true;
    }

    bool isBalanced(TreeNode *root, int &depth)
    {
        if(root== NULL) {
            depth = 0;
            return true;
        }
        int left_depth = 0;
        int right_depth = 0;

        if(!isBalanced(root->left, left_depth) || !isBalanced(root->right, right_depth)) return false;
        left_depth++;
        right_depth++;
        if (left_depth +1 < right_depth || left_depth - 1> right_depth) return false;

        depth = left_depth > right_depth? left_depth:right_depth;
        return true;
    }
};
