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
    bool hasPathSum(TreeNode* root, int t) {
        if(!root && t==0)return false;
        return solve(root, t);
    }
    bool solve(TreeNode* root, int t){
        if(!root){
            if(t==0)return true;
            else return false;
        }
        if(root->left && root->right)return solve(root->left, t-root->val)||solve(root->right, t-root->val);
        if(root->left)return solve(root->left, t-root->val);
        return solve(root->right, t-root->val);
    }
};