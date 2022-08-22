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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int> m;
        for(int i = 0;i<in.size();i++)m[in[i]]=i;
        
        return solve(pre, in , 0, pre.size()-1,0,m); 
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in, int i, int j, int l,unordered_map<int,int> &m){
        if(i>j)return NULL;
        
        TreeNode* head = new TreeNode(pre[i]);
        // cout<<pre[i]<<" "<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
        
        int p = m[pre[i]];
        head->left = solve(pre, in, i+1, i+p-l, l,m);
        head->right = solve(pre, in,i+1+p-l, j, p+1,m);
        return head;
    }
};