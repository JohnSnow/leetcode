#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1, *p2;
        p1 = p2 = head;

        if(head == NULL) {
            return NULL;
        }

        while(n > 0 && p1->next != NULL)
        {
            p1 = p1->next;
            n--;
        }

        if(n > 1) {
            return head;
        }else if(n == 1) {
            return head->next;
        }

        while(p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }

        p2->next = p2->next->next;
        return head;
    }
};
