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
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root)return ans;
        solve(ans, root, "");
        return ans;
    }
    void solve(vector<string> &ans, TreeNode* root, string s){
        if(s=="")s+=to_string(root->val);
        else s+= "->"+to_string(root->val);
        if(root->left)solve(ans, root->left, s);
        if(root->right)solve(ans, root->right, s);
        else if(!root->left && !root->right) ans.push_back(s);
        
        
    }
};