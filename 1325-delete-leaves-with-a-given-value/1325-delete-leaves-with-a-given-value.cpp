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
    bool check_leave(TreeNode* root){
        if(!root)return false;
        return !root->left && !root->right;
    }
    int solve(TreeNode* root, int t){
        if(!root)return 0;
        if(check_leave(root)){
            if(root->val==t)return -1;
            return 0;
        }
        int l= solve(root->left,t),r = solve(root->right,t);
        if(l==-1)root->left = NULL;
        if(r==-1)root->right= NULL;
        if(check_leave(root)){
            if(root->val==t)return -1;
            return 0;
        }
        return 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int v = solve(root, target);
        return v==-1?NULL:root;
    }
};