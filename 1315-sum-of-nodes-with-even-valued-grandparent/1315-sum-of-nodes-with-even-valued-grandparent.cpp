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
    int sum = 0;
    void solve(TreeNode* root, int p, int gp){
        if(!root)return;
        if(gp!=-1 && gp%2==0)sum+=root->val;
        solve(root->left, root->val, p);
        solve(root->right, root->val, p);
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root, -1, -1);
        return sum;
    }
};