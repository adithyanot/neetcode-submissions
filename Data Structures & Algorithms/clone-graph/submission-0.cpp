/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node,set<int>& s){
        if(!node){
            return node;
        }
        if(s.find(node->val) == s.end()){
            s.insert(node->val);
            Node* res = new Node(node->val,node->neighbors);
            vector<Node*> nbrs = node->neighbors;
            for(int i=0;i<nbrs.size();i++){
                dfs(nbrs[i],s);
            }
            return res;
        }
        return node;


    }
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        set<int> s;


        
        
    }
};
