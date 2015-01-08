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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        vector<int> vp, vq;
        inOrder(p, vp);
        inOrder(q, vq);

        if(vp.size()!= vq.size()) return false;

        postOrder(p, vp);
        postOrder(q, vq);

        vector<int>::const_iterator p_it, q_it;
        for(p_it = vp.begin(), q_it =vq.begin(); p_it != vp.end() && q_it!=vq.end(); p_it++, q_it++)
        {
            if(*p_it != *q_it) return false;
        }
        return true;
    }

    void inOrder(TreeNode *root, std::vector<int> &vec)
    {
        if(root==NULL) return;
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }

    void postOrder(TreeNode *root, std::vector<int> &vec)
    {
        if(root==NULL) return;
        postOrder(root->left, vec);
        postOrder(root->right, vec);
        vec.push_back(root->val);
    }


};
