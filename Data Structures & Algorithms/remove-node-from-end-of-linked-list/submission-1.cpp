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
        while(iter->next){
            iter = iter->next;
            len++;
        }
        int pos = len - n -1;
        if(pos<0){
            return head->next;
        }
        iter = head;
        while(pos>0){
            pos--;
            iter=iter->next;
        }
        iter->next = iter->next->next;
        return head;
    }
};
