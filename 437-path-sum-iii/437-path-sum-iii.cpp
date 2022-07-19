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
    int pathSum(TreeNode* root, int t) {
        unordered_map<long,int> s;
        s[0] = 1;
        solve(root, t, s,0);
        return ans;
    }
    void solve(TreeNode* root, int t,unordered_map<long,int> ss,long cur){
        
        if(!root)return;
        // cout<<root->val<<" "<<cur<<endl;
        long sum = cur+root->val;
        if(ss.find(sum-t)!=ss.end()){
            ans+=ss[sum-t];
        }
        ss[sum]++;
        solve(root->left, t,ss,sum);
        solve(root->right, t, ss, sum);
    }
    
};