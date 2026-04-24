/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode dummy(0);
            ListNode* result = &dummy;
            int count = 0;
            int a;
    
            while (l1 || l2) {
                if (!l1) {
                    a = l2->val + count;
                    count = 0;
                    if (a == 10) {
                        a = 0;
                        count = 1;
                    }
                    result = new ListNode(a);
                    result = result->next;
                    l2 = l2->next;
                    continue;
                }
                if (!l2) {
                    a = l1->val + count;
                    count = 0;
                     if (a == 10) {
                        a = 0;
                        count = 1;
                    }
                    result->next = new ListNode(a);
                    result = result->next;
                    l1 = l1->next;
                    continue;
                }
            result->next = new ListNode(l1->val + l2->val + count);
            count = 0;
    
            if (result->next->val >= 10) {
                count = 1;
                result->next->val = result->next->val - 10;
            }
            result = result->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
          };
          if (count == 1) {
                result = new ListNode(count);
                result = result->next;
           }
          return dummy.next;
        }
    };z