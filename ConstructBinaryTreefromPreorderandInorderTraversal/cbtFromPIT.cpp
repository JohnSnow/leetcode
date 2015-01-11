#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeW(preorder, 0, preorder.size() -1, inorder, 0, inorder.size() -1);
    }

    TreeNode *buildTreeW(
        vector<int> & preorder,
        int p_s, int p_e,
        vector<int> &inorder,
        int i_s, int i_e)
    {
        if(p_s > p_e) return NULL;

        TreeNode *root = new TreeNode(preorder[p_s]);

        int i;
        for(i = i_s; inorder[i] != root->val && i < i_e; i++) {
            ;
        }
        
        int distance = i - i_s;
        root->left = buildTreeW(preorder, p_s + 1, p_s + distance, inorder, i_s, i - 1);
        root->right = buildTreeW(preorder, p_s + distance + 1, p_e, inorder, i + 1, i_e);

        return root;
    }
};


int main(int argc, char *argv[])
{
    int a1[2] = {1,2};
    int a2[2] = {2,1};

    vector<int> v1(a1, a1+sizeof(a1)/sizeof(a1[0]));
    vector<int> v2(a2, a2+sizeof(a2)/sizeof(a2[0]));

    Solution *sl = new Solution();
    sl->buildTree(v1, v2);
    return 0;
}
