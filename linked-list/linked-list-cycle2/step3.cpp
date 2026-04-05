/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            std::unordered_set<ListNode*> visited;
            ListNode* current = head;
            while(current != nullptr){
                if(visited.find(current) != visited.end()){
                    return current;
                }
                visited.insert(current);
                current = current->next;
            }
            return nullptr;
        }
    };