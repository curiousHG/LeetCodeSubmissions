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
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        solve(root, 0);
        return ans; 
    }
    void solve(TreeNode* root,int cursum){
        int val = cursum*10+root->val;
        if(root->left)solve(root->left,val);
        if(root->right)solve(root->right,val);
        if(!root->left && !root->right)ans+=val;
    }
};






