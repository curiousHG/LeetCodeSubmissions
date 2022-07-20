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
    int ans = INT_MAX;
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        solve(root, 1);
        return ans;
    }
    void solve(TreeNode* root,int d){
        if(!root)return;
        if(!root->left && !root->right){
            ans = min(ans,d);
            return;
        }
        solve(root->left, d+1);
        solve(root->right,d+1);
        
        
    }
};