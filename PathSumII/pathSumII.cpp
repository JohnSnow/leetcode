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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > vv;
        vector<int> vec;

        if(root == NULL) return vv;

        pathSum2(root, sum, vv, vec);
        return vv;
    }

    void pathSum2(TreeNode *root, int sum, vector<vector<int> > &vv, vector<int> &vec) {
        if(!root->left && !root->right) {
            if(root->val == sum) {
                vector<int> fVec(vec);
                fVec.push_back(root->val);
                vv.push_back(fVec);
            }
        }

        int newSum = sum - root->val;
        vec.push_back(root->val);

        if(root->left) {
            pathSum2(root->left, newSum, vv, vec);
        }
        if(root->right) {
            pathSum2(root->right, newSum, vv, vec);
        }
        vec.pop_back();
    }
};
