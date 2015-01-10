#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *head, *p;
        if(l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        p = head;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if(l1 == NULL) p->next = l2;
        if(l2 == NULL) p->next = l1;

        return head;
    }
};


int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(-9);
    l1->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(7);

    Solution *sl = new Solution();
    sl->mergeTwoLists(l1, l2);
    return 0;
}
