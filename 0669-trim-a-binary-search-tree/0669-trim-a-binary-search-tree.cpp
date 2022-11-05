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
    TreeNode* solve(TreeNode* root, int l ,int h){
        if(!root)return NULL;
        TreeNode* nl = solve(root->left, l, h);
        TreeNode* nr = solve(root->right, l, h);
        if(root->val<l){
            return nr;
        }else if(root->val>h){
            return nl;
        }else{
            root->left = nl;
            root->right = nr;
            return root;
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};