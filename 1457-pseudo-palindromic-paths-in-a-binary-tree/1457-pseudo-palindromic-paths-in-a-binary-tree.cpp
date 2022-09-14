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
    int ans = 0;
    bool check(unordered_map<int,int> &mp){
        bool d = true;
        for(auto &x:mp){
            if(x.second%2==1){
                if(d)d = false;
                else return false;
            }
        }
        return true;
    }
    void solve(TreeNode* root, unordered_map<int,int> &mp){
        if(!root)return;
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL){
            if(check(mp))ans++;
        }
        solve(root->left,mp);
        solve(root->right,mp);
        mp[root->val]--;
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        solve(root,mp);
        return ans;
    }
};