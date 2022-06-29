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
    int maxi;
    int maxPathSum(TreeNode* root) {
        maxi = root->val;
        solve(root);
        return maxi;
    }
    int solve(TreeNode* root){
        if(!root)return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        maxi = max(maxi,left+right+root->val);
        maxi = max(maxi,left+root->val);
        maxi = max(maxi, right+root->val);
        return max(0,max(left, right)+root->val);
        
    }
};