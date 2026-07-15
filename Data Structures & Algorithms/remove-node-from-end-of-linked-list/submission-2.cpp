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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next){
            return nullptr;
        }
        ListNode* iter = head;
        int len = 1;
        while(len <=n){
            iter = iter->next;
            len++;
        }
        ListNode* dummy = new ListNode(0,head);
        ListNode* ptr =  dummy;
        while(iter){
            iter = iter->next;
            ptr = (ptr)->next;
        }
        ptr->next = ptr->next->next;
        return dummy->next;
        
    }
};
