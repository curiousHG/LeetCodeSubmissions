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
    vector<vector<int>> pathSum(TreeNode* root, int tS) {
        vector<vector<int>> ans;
        if(!root)return ans;
        solve(root, 0, tS, vector<int>(), ans);
        return ans;
    }
    void solve(TreeNode* root, int cs, int ts, vector<int> temp, vector<vector<int>> &ans){
        if(root && cs+root->val==ts && !root->left && !root->right){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        if(!root)return;
        temp.push_back(root->val);
        solve(root->left, cs+root->val, ts, temp, ans);
        solve(root->right, cs+root->val, ts, temp, ans);
        temp.pop_back();
        
    }
};