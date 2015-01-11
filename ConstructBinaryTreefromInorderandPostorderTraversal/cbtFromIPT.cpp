#include <iostream>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty()) return NULL;
        if(inorder.size() != postorder.size() ) return NULL;

        size_t  size = postorder.size();

        return buildTree(inorder, 0, size -1 , postorder, 0, size - 1);

    }

    TreeNode *buildTree(vector<int> &inorder, int in_s, int in_e, vector<int> &postorder, int post_s, int post_e)
    {
        if(in_s >in_e) return NULL;
        if(in_s == in_e) return new TreeNode(inorder[in_s]);

        TreeNode *root = new TreeNode(postorder[post_e]);

        vector<int>::iterator in_it;

        in_it = std::find(inorder.begin() + in_s, inorder.begin() + in_e + 1, root->val);

        int idx = in_it - inorder.begin();
        int distance = idx - in_s;

        root->left = buildTree(inorder, in_s, in_s + distance - 1, postorder, post_s, post_s + distance -1);
        root->right = buildTree(inorder, in_s + distance + 1, in_e, postorder, post_s + distance , post_e -1);
        return root;
    }
};

int main(int argc, char *argv[])
{
    int a1[4] = {1,2,3,4};
    vector<int> v1(a1, a1 +sizeof(a1)/sizeof(a1[0]));

    int a2[4] = {3,2,4,1};
    vector<int> v2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    
    Solution *sl = new Solution();
    sl->buildTree(v1, v2);
    return 0;
}
