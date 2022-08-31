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
    int mod = 1e9+7;
    long long t = 0;
    long long maxi = 0;
    long long solve(TreeNode* root){
        if(!root)return 0;
        long long l = solve(root->left);
        long long r = solve(root->right);
        long long val = l+r+root->val;
        maxi = max(maxi, (val*1ll*(t-val)));
        return val;
        
    }
    int maxProduct(TreeNode* root) {
        t = solve(root);
        solve(root);
        return maxi%mod;
    }
};