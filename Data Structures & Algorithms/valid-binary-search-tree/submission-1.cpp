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
    int dfs(TreeNode*root, int min , int max){
        if(!root){
            return true;
        }
        if(root->val >= max || root->val <= min){
            return false;
        }
        bool left = dfs(root->left,min,root->val);
        bool right = dfs(root->right,root->val,max);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        bool res = dfs(root,INT_MIN,INT_MAX);
        return res;

    }
        
        
};
