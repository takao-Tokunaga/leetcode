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
            std::vector<ListNode*> list_node;
            ListNode* current_node = head;
            while(current_node != nullptr){
            for(int i = 0; i < list_node.size(); ++i){
                if(list_node.at(i) == current_node){
                    return list_node.at(i);
                }
            }
                list_node.push_back(current_node);
                current_node = current_node->next;
            }
            return nullptr;
        }
    };