#include <vector>
#include <iostream>

using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > retVector;
        vector<vector<TreeNode *> > tmp;
        if(root == NULL) { return retVector; }

        vector<TreeNode *> v1;
        v1.push_back(root);
        tmp.push_back(v1);
        unsigned i = 0;
        while(i < tmp.size()) {
            vector<TreeNode *> prev = tmp[i];
            vector<TreeNode *> cur;
            for(vector<TreeNode *>::const_iterator it=prev.begin(); it!=prev.end(); it++)
            {
                if((*it)->left) cur.push_back((*it)->left);
                if((*it)->right) cur.push_back((*it)->right);
            }
            if(!cur.empty()) {
                tmp.push_back(cur);
            }
            i++;
        }

        for(vector<vector<TreeNode *> >::const_iterator it=tmp.begin(); it != tmp.end(); it++)
        {
            vector<int> curr;
            for(vector<TreeNode*>::const_iterator it1 = (*it).begin(); it1 != (*it).end(); it1++) {
                curr.push_back((*it1)->val);
            }
            retVector.push_back(curr);
        }
        return retVector;
    }
};

