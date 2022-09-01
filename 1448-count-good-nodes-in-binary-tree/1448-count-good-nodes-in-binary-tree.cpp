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
    int ans = 0;
    void solve(TreeNode* root, int val){
        if(!root)return;
        if(root->val>=val)ans++;
        solve(root->left, max(root->val,val));
        solve(root->right, max(root->val,val));
    }
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};