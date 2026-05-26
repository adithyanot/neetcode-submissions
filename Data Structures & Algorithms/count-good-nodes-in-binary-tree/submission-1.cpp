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
    int dfs(TreeNode*root, int maxNodeval){
        if(!root){
            return 0;
        }
        int goodNode =0;
        if(root->val >= maxNodeval){
            goodNode ++;
            maxNodeval = max(maxNodeval,root->val);

        }
        int leftgood = dfs(root->left,maxNodeval);
        int rightgood = dfs(root->right,maxNodeval);
        goodNode += leftgood;
        goodNode += rightgood;
        return goodNode;
    }
public:
    int goodNodes(TreeNode* root) {
        int maxgood = root->val;
        int ans = dfs(root,maxgood);
        return ans;
        
    }
};
