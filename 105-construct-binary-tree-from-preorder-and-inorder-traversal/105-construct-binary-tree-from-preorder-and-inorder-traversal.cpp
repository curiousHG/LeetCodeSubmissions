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
        return solve(pre, in , 0, pre.size()-1,0, pre.size()-1); 
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in, int i, int j, int l , int r){
        if(i>j)return NULL;
        
        TreeNode* head = new TreeNode(pre[i]);
        // cout<<pre[i]<<" "<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
        
        int p = l;
        while(in[p++]!=pre[i]);
        p--;
        head->left = solve(pre, in, i+1, i+p-l, l, p-1);
        head->right = solve(pre, in,i+p-l+1, j, p+1, r);
        return head;
    }
};