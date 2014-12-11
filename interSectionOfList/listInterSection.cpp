#include <iostream>

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *pA = headA;
        ListNode *pB = headB;
        int sA = 0;
        int sB = 0;

        while(pA || pB) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;

            if (pA == NULL && sA == 0 ) {
                pA = headB;
                sA += 1;
            }
            if (pB == NULL && sB == 0 ) {
                pB = headA;
                sB = 1;
            }

        }
        return NULL;
    }
};


int main(int argc, const char *argv[])
{
    ListNode *headA = new ListNode(1);
    ListNode *nB = new ListNode(3);
    headA->next = nB;

    ListNode *headB = new ListNode(2);

    Solution *sl = new Solution();
    ListNode *ret = sl->getIntersectionNode(headA, headB);

    std::cout << ret->val << std::endl;

    return 0;
}
