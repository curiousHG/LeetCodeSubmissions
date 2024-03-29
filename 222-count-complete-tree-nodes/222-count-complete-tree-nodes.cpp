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
    int n = 0;
    void solve(TreeNode* root){
        if(!root)return;
        n++;
        solve(root->left);
        solve(root->right);
    }
    int countNodes(TreeNode* root) {
        solve(root);
        return n;
    }
};