#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        flattenLastNode(root);
    }

    TreeNode *flattenLastNode(TreeNode *root) {
        if(root == NULL) return NULL;

        if(root->left == NULL && root->right == NULL) {
            return root;
        }

        TreeNode *left_r, *right_r;
        left_r = right_r = NULL;

        TreeNode *right = root->right;

        if(root->left) {
            left_r = flattenLastNode(root->left);
            root->right = root->left;
            root->left = NULL;
        }
        if(right) {
            right_r = flattenLastNode(right);
            if(left_r) {
                left_r->right = right;
            }else {
                root->right = right;
            }
        }
        return right_r?right_r:left_r;
    }
};


int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution *sl = new Solution();
    sl->flatten(root);
    return 0;
}
