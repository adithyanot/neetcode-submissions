/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            for(int i=q.size();i>0;i--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp){
                    level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if(!level.empty()){
                int rightmost = level[level.size()-1];
                res.push_back(rightmost);
            }
        }
        return res;
        
    }
};
