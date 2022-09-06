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
    bool solve(TreeNode* root){
        if(!root)return false;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(!l)root->left = NULL;
        if(!r)root->right = NULL;
        if(root->val==1 || l|| r)return true;
        return false;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool t = solve(root);
        if(!t)root = NULL;
        return root;
    }
};