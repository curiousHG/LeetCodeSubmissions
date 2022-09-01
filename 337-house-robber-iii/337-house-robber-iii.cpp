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
    unordered_map<TreeNode*, int> mp;
    int solve(TreeNode* root){
        if(!root)return 0;
        if(mp.find(root)!=mp.end())return mp[root];
        int v = root->val;
        if(root->left){
            v+=solve(root->left->left);
            v+=solve(root->left->right);
        }
        if(root->right){
            v+=solve(root->right->left);
            v+=solve(root->right->right);
        }
        return mp[root] = max(v, solve(root->left)+solve(root->right));
        
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};