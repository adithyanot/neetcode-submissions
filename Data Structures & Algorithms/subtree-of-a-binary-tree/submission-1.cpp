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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }else if(!p || !q){
            return false;

        }
        if(p->val != q ->val){
            return false;
        }
        bool leftsame = isSameTree(p->left,q->left);
        bool rightsame = isSameTree(p->right,q->right);
        return leftsame&&rightsame;

        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool issame = isSameTree(root,subRoot);
        if(issame){
            return true;
        }else{
            bool issameleft=false;
            bool issameright=false;
            if(root->left){
                issameleft = isSubtree(root->left,subRoot);

            }
            if(root->right){
                issameright= isSubtree(root->right,subRoot);
                

            }
            
            
            return issameleft || issameright;
        }
        
    }
};
