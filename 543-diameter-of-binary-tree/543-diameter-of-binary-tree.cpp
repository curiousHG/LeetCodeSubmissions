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
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxi;
    }
    int solve(TreeNode* root){
        int dl = 0,dr = 0;
        if(root->left && root->right){
            dl = solve(root->left);
            dr = solve(root->right);
            maxi = max(maxi, dl+dr+2);
            return max(dl,dr)+1;
        }
        if(root->left){
            dl = solve(root->left);
            maxi = max(maxi, dl+1);
            return dl+1;
        }
        if(root->right){
            dr = solve(root->right);
            maxi = max(maxi, dr+1);
            return dr+1;
        }
        return 0;
    }
};