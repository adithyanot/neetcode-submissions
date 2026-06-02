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
    Node* dfs(Node* node,unordered_map<int,Node*>& s){
        if(!node){
            return node;
        }
        if(s.find(node->val) == s.end()){
            Node* res = new Node(node->val);
            s[node->val] = res;
            vector<Node*> nbrs = node->neighbors;
            cout<<node->val<<" "<<endl;
            vector<Node*> new_nbrs;
            for(int i=0;i<nbrs.size();i++){
                Node* nbr = dfs(nbrs[i],s);
                new_nbrs.push_back(nbr);
                
            }
            res->neighbors = new_nbrs;
            return res;
        }
        return s[node->val];


    }
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        unordered_map<int,Node*> s;
        Node* res = dfs(node,s);

        return res;
    


        
        
    }
};
