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
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* prev = dummy;
            ListNode* current = head;
    
            while(current && current->next) {
                if (current->val == current->next->val) {
                    while (current->next && current->val == current->next->val) {
                        current = current->next;
                    }
                    prev->next = current->next; 
                } else {
                    prev = current;
                }
                current = current->next; 
            }
            return dummy->next;
            
        }
    };