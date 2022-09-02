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
    vector<vector<int>> temp;
    void solve(TreeNode* n, int l){
        if(!n)return;
        if(temp.size()==l)temp.push_back(vector<int>());
        temp[l].push_back(n->val);
        solve(n->left,l+1);
        solve(n->right,l+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root,0);
        vector<double> ans;
        for(int i = 0;i<temp.size();i++){
            double val =(double)accumulate(temp[i].begin(),temp[i].end(),0ll)/temp[i].size();
            ans.push_back(val);
        }
        return ans;
    }
};