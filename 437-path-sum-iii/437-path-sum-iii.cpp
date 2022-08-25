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
#define ll long
class Solution {
public:
    int ans = 0;
    int pathSum(TreeNode* root, int t) {
        unordered_map<ll,int> m;
        m[0] = 1;
        solve(root, t, m,0);
        return ans;
    }
    void solve(TreeNode* root, int t, unordered_map<ll,int> &m, ll cur){
        if(!root)return;
        ll n = cur+root->val;
        if(m.find(n-t)!=m.end()){
            ans+=m[n-t];
        }
        m[n]++;
        solve(root->left,t,m, n);
        solve(root->right,t,m, n);
        m[n]--;
        
        
    }
};