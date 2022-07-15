/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
        path(root, p, a);
        path(root, q, b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        // for(int i = 0;i<a.size();i++){
        //     cout<<a[i]->val<<" ";
        // }
        // cout<<endl;
        // for(int i = 0;i<b.size();i++){
        //     cout<<b[i]->val<<" ";
        // }
        // cout<<endl;
        for(int i= 0;i<min(a.size(),b.size());i++){
            if(a[i]->val!=b[i]->val){
                return a[i-1];
            }
        }
        // return 0;
        return a.size()<b.size()?a[a.size()-1]:b[b.size()-1];
    }
    bool path(TreeNode* root, TreeNode* n,vector<TreeNode*> &a){
        if(!root)return false;
        if(root==n){
            a.push_back(root);
            return true;
        }else{
            bool l = path(root->left, n, a);
            bool r = path(root->right, n, a);
            if(l){
                a.push_back(root);
                return true;
            }
            if(r){
                a.push_back(root);
                return true;
            }
            return false;
        }
    }
};