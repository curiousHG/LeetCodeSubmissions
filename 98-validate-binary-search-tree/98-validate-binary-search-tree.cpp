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
    bool isValidBST(TreeNode* root) {
        bool left = true,right = true;
        if(root->left){
            if(root->left->val>=root->val)return false;
            int m = maxi(root->left);
            if(m>=root->val)return false;
            left =  isValidBST(root->left);
        }
        if(root->right){
            if(root->right->val<=root->val)return false;
            int m = mini(root->right);
            if(m<=root->val)return false;
            right = isValidBST(root->right);
        }
        return left&&right;
        
    }
    int maxi(TreeNode* root){
        int m = root->val;
        while(root){
            m = max(m,root->val);
            root = root->right;
        }
        return m;
        
    }
    int mini(TreeNode* root){
        int m = root->val;
        while(root){
            m = min(m,root->val);
            root = root->left;
        }
        return m;
    }
};