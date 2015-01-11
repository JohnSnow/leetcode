#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > retVec;
        std::stack<TreeNode*> st;
        std::deque<TreeNode *> Q;
        if(root == NULL) return retVec;

        vector<int> vec;
        Q.push_back(root);
        int level = 0;
        int parentSize = 1;
        int childSize = 0;

        TreeNode* cur = NULL;

        while(!Q.empty()) {
            cur = Q.front();
            Q.pop_front();

            if((level & 0x1) == 0) {
                vec.push_back(cur->val);
            }
            if(cur->left) {
                Q.push_back(cur->left);
                childSize++;
                if((level & 0x1) == 0) st.push(cur->left);
            }
            if(cur->right) {
                Q.push_back(cur->right);
                childSize++;
                if((level & 0x1) == 0) st.push(cur->right);
            }

            if(--parentSize == 0) {
                parentSize = childSize;
                childSize = 0;
                if((level & 0x1)== 1) {
                    while(!st.empty()) {
                        vec.push_back(st.top()->val);
                        st.pop();
                    }
                }
                retVec.push_back(vec);
                vec.clear();
                level++;
            }
        }
        return retVec;
    }
};

int main(int argc, char *argv[]) 
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->right->right = new TreeNode(5);


    Solution *sl = new Solution();
    sl->zigzagLevelOrder(root);
    return 0;
}
