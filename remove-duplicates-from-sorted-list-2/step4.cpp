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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode dummy(-1, head);
            ListNode* prev = &dummy;
            while (prev->next) {
                ListNode* current = prev->next;
                if (!current->next || current->val != current->next->val) {
                    prev = prev->next;
                    continue;
                }
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } 
            return dummy.next;
        }
    };