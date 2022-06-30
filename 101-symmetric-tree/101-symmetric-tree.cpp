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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right)return true;
        if((!root->left && root->right)||(!root->right && root->left)) return false;
        if(root->left->val!=root->right->val)return false;
        return recur(root->left, root->right);
    }
    bool recur(TreeNode* left,TreeNode* right){
        if(!left && !right)return true;
        if((!left && right)||(!right && left)) return false;
        if(right->val==left->val){
            return recur(left->right,right->left)&&recur(left->left,right->right);
        }else{
            return false;
        }
        
    }
};