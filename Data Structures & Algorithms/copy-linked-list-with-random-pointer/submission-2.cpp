/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        unordered_map<Node*,Node*>mp;
        Node* iter = head;
        Node* new_head = new Node(iter->val);
        mp[iter] = new_head;
        Node* prev = new_head;
        iter = iter->next;
        while(iter){
            Node* curr = new Node(iter->val);
            mp[iter] = curr;
            if(prev){
                prev->next = curr;
            }
            prev = curr;
            iter = iter->next;
        }
        iter = head;
        Node* iter2 = new_head;
        while(iter){
            iter2->random = mp[(iter->random)];
            iter =iter->next;
            iter2 = iter2->next;
        }
        return new_head;

        
        
    }
};
