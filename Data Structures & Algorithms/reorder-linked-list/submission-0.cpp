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
    ListNode* reverse(ListNode* head){
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
public:
    void reorderList(ListNode* head) {
        ListNode* iter = head;
        int length =1;
        while(iter->next){
            iter = iter->next;
            length ++;
        }
        iter = head;
        length = length/2;
        while(length>1){
            iter = iter->next;
            length--;
        }
        ListNode* second_head = iter->next;
        iter->next = nullptr;
        second_head = reverse(second_head);
        iter = head;
        ListNode* iter2 = second_head;
        while( iter && iter2){
            ListNode*temp1 = iter->next;
            ListNode*temp2 = iter2->next;
            iter->next = iter2;
            iter2->next = temp1==nullptr? iter2->next:temp1;
            iter= temp1;
            iter2 = temp2;
        }

        
        
    }
};
