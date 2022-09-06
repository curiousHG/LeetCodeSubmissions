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
    bool check(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)return true;
        else if(root1 && !root2)return false;
        else if(!root1 && root2)return false;
        else if(root1->val!=root2->val)return false;
        return check(root1->left, root2->left) && check(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(check(root, sub))return true;
        if((root && !sub )|| (!root && sub))return false;
        if(root)return isSubtree(root->left, sub)||isSubtree(root->right, sub);
        return true;
    }
};