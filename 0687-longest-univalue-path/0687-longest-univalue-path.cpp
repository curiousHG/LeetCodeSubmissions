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
    int maxi = 0;
    int solve(TreeNode* root, int prev){
        if(!root)return 0;
        int l = solve(root->left, root->val);
        int r = solve(root->right, root->val);
        int val = max(l,r);
        maxi = max(maxi, 1+l+r);
        if(prev==root->val){
            return val+1;
        }else{
            return 0;
        }
        
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root, 1001);
        if(!root)return 0;
        return maxi-1;
    }
};