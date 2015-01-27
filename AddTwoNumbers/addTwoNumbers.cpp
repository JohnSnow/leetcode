#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *p1, *p2, *p1prev;
        p1 = l1; p2 = l2;
        int plus = 0;

        while(p1 && p2) {
            int val = p1->val + p2->val + plus;
            if(val > 9) {
                p1->val = val - 10; 
                plus = 1;
            }else{
                plus = 0;
            }
            p1prev = p1;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==NULL) {
            p1prev->next = p2;
            p1=p2;
        }
        while(p1) {
            int val = p1->val + plus;
            if(val > 9) {
                p1->val = val - 10;
                plus = 1;
            } else {
                plus = 0;
            }

            p1prev = p1;
            p1 = p1->next;
        }
        if(plus == 1) {
            p1prev->next = new ListNode(1);
        }
        return l1;
    }
};

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);

    Solution *sl = new Solution();
    sl->addTwoNumbers(l1, l2);
    return 0;
}
