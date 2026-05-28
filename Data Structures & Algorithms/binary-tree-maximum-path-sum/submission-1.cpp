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
    int dfs(TreeNode* root, int& maxSum){
        if(!root){
            return 0;
        }
        int leftsum = dfs(root->left,maxSum);
        int rightsum = dfs(root->right,maxSum);
        int sum = max(0,leftsum) + max(0,rightsum) + root->val;
        maxSum = max(maxSum,sum);
        return root->val + max(0,max(leftsum,rightsum)); 
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root,maxSum);
        return maxSum;

    }
};
