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
    int dfs(TreeNode* root, bool& balanced) {
        if(!root){
            return 0;
        }
        int left_depth = dfs(root->left,balanced);
        int right_depth = dfs(root->right,balanced);
        bool bal = abs(left_depth - right_depth) < 2;
        balanced = balanced & bal;
        int depth =1+  max(left_depth,right_depth);
        return depth;
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        bool balanced = true;
        dfs(root,balanced);
        return balanced;

        
        
    }
};
