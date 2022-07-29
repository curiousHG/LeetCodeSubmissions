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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int d;
        if(!root)return ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<TreeNode*, int> cur = q.front();
            TreeNode* n = cur.first;
            d = cur.second;
            q.pop();
            if(d==ans.size()){
                ans.push_back(vector<int>());
            }
            ans.back().push_back(n->val);
            if(n->left)q.push(make_pair(n->left, d+1));
            if(n->right)q.push(make_pair(n->right, d+1));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};