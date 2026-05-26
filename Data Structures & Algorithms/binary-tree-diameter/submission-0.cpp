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
    int dfs(TreeNode* root,int&diameter) {
        if(!root){
            return 0;
        }
        int left_depth = dfs(root->left,diameter);
        int right_depth = dfs(root->right,diameter);
        diameter = max(left_depth+right_depth,diameter);
        int depth =1+  max(left_depth,right_depth);
        return depth;
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        int depth = dfs(root,diameter);
        return diameter;

        
        
        
    }
};
