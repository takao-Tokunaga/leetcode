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
            ListNode* current = head;
            ListNode* next = head;
            while (next != nullptr) {
                while (next != nullptr && next->val == current->val) {
                    next = next->next;
                }
                current->next = next;
                current = next;
                if (next != nullptr) {
                    next = next->next;
                }
            }
            return head;   
        }
    };