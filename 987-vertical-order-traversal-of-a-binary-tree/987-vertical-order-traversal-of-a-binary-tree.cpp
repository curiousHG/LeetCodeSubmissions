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
    int l = 0, r = 0, d;
    unordered_map<int, vector<pair<int,int>>>mp;
    void width(TreeNode* root, int c,int dep){
        if(!root)return;
        l = min(l, c);
        r = max(r, c);
        width(root->left, c-1,dep+1);
        if(mp.find(c)==mp.end()){
            vector<pair<int,int>> tmp;
            mp[c] = tmp;
        }
        mp[c].push_back({dep,root->val});
        
        width(root->right, c+1,dep+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        width(root, 0, 0);
        vector<vector<int>> ans;
        for(int i = l;i<=r;i++){
            sort(mp[i].begin(),mp[i].end());
            ans.push_back(vector<int>());
            for(auto& z:mp[i])ans.back().push_back(z.second);
        }
        return ans;
    }
};