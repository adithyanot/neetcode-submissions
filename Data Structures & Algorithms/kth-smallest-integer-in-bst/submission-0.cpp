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
    int dfs(TreeNode* root,int& count,int k,int&res){
        if(!root){
            return 0;
        }
        dfs(root->left,count,k,res);
        count++;
        if(count == k){
            res = root->val;
        }
        dfs(root->right,count,k,res);
        return 0;
        

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int c =0;
        int res=0;
        dfs(root,c,k,res);
        return res;
        
    }
};
