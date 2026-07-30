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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int count =0;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        while(count<k){
            int mini = INT_MAX;
            int mini_it = 0;
            for(int i=0;i<k;i++){
                if(lists[i] && lists[i]->val < mini){
                    mini = lists[i]->val;
                    mini_it = i;  
                }
            }
            ListNode* curr = new ListNode(mini);
            prev->next = curr;
            prev = prev->next;
            lists[mini_it] = lists[mini_it]->next;
            if(!lists[mini_it]){
                count++;
            }
        }
        return dummy->next ;
        
    }
};
