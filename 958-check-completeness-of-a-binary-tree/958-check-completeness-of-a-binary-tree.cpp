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
    bool isCompleteTree(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> qu;
        qu.push(root);
        bool found = false;
        while(!qu.empty()){
            TreeNode* temp = qu.front();
            qu.pop();
            if(found && temp)return false;
            if(temp==NULL)found = true;
            if(temp){
                qu.push(temp->left);
                qu.push(temp->right);
            }
            
        }
        return true;
        
    }
};