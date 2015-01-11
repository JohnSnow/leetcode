#include <iostream>
#include <deque>
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {

public:
    void connect(TreeLinkNode *root) {
/*        if(root == NULL) return;*/
        //std::deque<TreeLinkNode *> _deque;
        //TreeLinkNode *Empty = NULL;
        //TreeLinkNode *cur = NULL;

        //_deque.push_back(root);
        //_deque.push_back(Empty);
        //while(!_deque.empty()) {
            //cur = _deque.front();
            //_deque.pop_front();
            //if(cur) {
                //_deque.pop_front();
                //cur->next = _deque.front();
                //if(cur->left!=NULL) _deque.push_back(cur->left);
                //if(cur->right!=NULL) _deque.push_back(cur->right);
            //} else {
                //if(!_deque.empty()) {
                    //_deque.push_back(Empty);
                    //continue;
                //}
            //}
        /*}*/

        if(root==NULL) return;
        std::deque<TreeLinkNode*> _deque ;
        TreeLinkNode * cur = NULL;

        _deque.push_back(root);
        int parentSize = 1;
        int childSize = 0;

        while(!_deque.empty()) {
            cur = _deque.front();
            _deque.pop_front();

            if(cur->left) {
                _deque.push_back(cur->left);
                childSize++;
            }
            if(cur->right) {
                _deque.push_back(cur->right);
                childSize++;
            }

            if(--parentSize == 0) {
                cur->next = NULL;
                parentSize = childSize;
                childSize = 0;
            } else {
                cur->next = _deque.front();
            }
        }
    }
};
