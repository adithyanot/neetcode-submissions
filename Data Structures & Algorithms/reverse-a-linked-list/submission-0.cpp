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
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)){
            return head;
        }
        ListNode * iter = head;
        ListNode * iter_next = head->next;
        head->next = NULL;
        while(iter_next != NULL){
            ListNode *temp = iter_next->next;
            iter_next->next = iter;
            iter = iter_next;
            iter_next = temp;
        }
        return iter;
        
     
        
    }
};
