#include <climits>
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
/*    bool isSymmetric(TreeNode *root) {*/
        //if(root== NULL) return true;
        //std::vector<int> left;
        //std::vector<int> right;

        //postOrder(root->left, left);
        //revresedPostOrder(root->right, right);

        //inOrder(root->left, left);
        //reversedInOrder(root->right, right);

        //std::vector<int>::const_iterator left_it;
        //std::vector<int>::const_iterator right_it;

        //if(left.size() != right.size()) return false;

        //for(left_it = left.begin(), right_it = right.begin(); left_it != left.end() || right_it!=right.end(); left_it++, right_it++)
        //{
            //std::cout << *left_it << " " << *right_it<< std::endl;
            //if(*left_it != *right_it) return false;
        //}

        //return true;
    //}

    //void inOrder(TreeNode *root, std::vector<int> &vec)
    //{
        //if(root==NULL) return;
        //inOrder(root->left, vec);
        //vec.push_back(root->val);
        //inOrder(root->right, vec);
    //}

    //void reversedInOrder(TreeNode *root, std::vector<int> &vec)
    //{
        //if(root==NULL) return;
        //reversedInOrder(root->right, vec);
        //vec.push_back(root->val);
        //reversedInOrder(root->left, vec);

    //}

    //void postOrder(TreeNode *root, std::vector<int> &vec)
    //{
        //if(root==NULL) return;
        //postOrder(root->left, vec);
        //postOrder(root->right, vec);
        //vec.push_back(root->val);
    //}

    //void revresedPostOrder(TreeNode *root, std::vector<int> &vec)
    //{
        //if(root==NULL) return;
        //revresedPostOrder(root->right, vec);
        //revresedPostOrder(root->left, vec);
        //vec.push_back(root->val);
    /*}*/

    bool isSymmetric(TreeNode *root) {
        if(root== NULL) return true;

        vector<TreeNode* > v1;
        v1.push_back(root);

        TreeNode *fakeNode = new TreeNode(INT_MAX);

        while (!v1.empty()) {
            vector<int> v_int;
            vector<TreeNode*> tmp;
            for(vector<TreeNode*>::iterator it = v1.begin(); it!=v1.end(); it++)
            {
                if(*it == fakeNode) continue;

                if((*it)->left != NULL){
                    tmp.push_back((*it)->left);
                } else {
                    tmp.push_back(fakeNode);
                }

                if((*it)->right != NULL) {
                    tmp.push_back((*it)->right);
                } else {
                    tmp.push_back(fakeNode);
                }
            }
            if((tmp.size() & 0x1) != 0) return false;
            if(tmp.empty()) return true;

            for(vector<TreeNode*>::iterator it = tmp.begin(); it!=tmp.end(); it++)
            {
                v_int.push_back((*it)->val);
            }
            if(!isSymmetric(v_int)) return false;
            v1 = tmp;
        }
        return true;
    }

    bool isSymmetric(vector<int> const &vec )
    {
        vector<int>::const_iterator l_it;
        vector<int>::const_iterator r_it;

        for(l_it=vec.begin(), r_it = vec.end() -1; l_it < r_it; l_it++, r_it--)
        {
            if(*l_it != *r_it) return false;
        }
        return true;
    }

};


TreeNode *createTree()
{
    TreeNode *root= new TreeNode(2);
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(8);
    TreeNode *n8 = new TreeNode(8);

    TreeNode *n9 = new TreeNode(9);
    TreeNode *n10 = new TreeNode(9);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    n4->left = n7;
    n4->right = n9;
    n5->left = n10;
    n5->right = n8;

    return root;
}

int main(int argc, char *argv[])
{
    TreeNode *root = createTree();
    Solution *sl = new Solution();
    std::cout << sl->isSymmetric(root) << std::endl;
    
    return 0;
}
