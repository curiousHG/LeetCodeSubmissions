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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
    void solve(TreeNode* root, int d){
        if(!root)return;
        if(ans.size()==d){
            ans.push_back(root->val);
        }else{
            ans[d] = root->val;
        }
        solve(root->left,d+1);
        solve(root->right,d+1);
        
    }
};