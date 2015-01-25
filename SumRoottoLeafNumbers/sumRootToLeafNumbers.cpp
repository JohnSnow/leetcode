#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        int base = 0;
        int sum = 0;
        sumNumbersR(root, base, sum);
        return sum;

    }

    void sumNumbersR(TreeNode* root, int base, int &sum) {
        base = 10*base + root->val;

        if(root->left==NULL && root->right == NULL) {
            sum += base;
            return;
        }
        if(root->left) {
            sumNumbersR(root->left, base, sum);
        }

        if(root->right) {
            sumNumbersR(root->right, base, sum);
        }
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution *sl = new Solution();
    std::cout << sl->sumNumbers(root) << std::endl;
    return 0;
}
