#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;

        int length = 0;
        ListNode *p = head;
        ListNode *right=NULL;
        while(p) {
            length++;
            p = p->next;
        }

        if(length == 1) return new TreeNode(head->val);
        if(length == 2) {
            TreeNode *p1 = new TreeNode(head->val);
            p1->right = new TreeNode(head->next->val);
            return p1;
        }
        p = head;
        for(int i=0; i< length/2 - 1; i++) {
            p = p->next;
        }

        TreeNode *newHead = new TreeNode(p->next->val);
        right = p->next->next;
        p->next = NULL;
        newHead->left = sortedListToBST(head);
        newHead->right = sortedListToBST(right);

        return newHead;
    }
};
