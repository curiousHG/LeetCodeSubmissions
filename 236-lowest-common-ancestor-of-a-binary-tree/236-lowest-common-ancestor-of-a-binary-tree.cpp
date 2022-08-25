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
        int n = a.size(),m = b.size();
        for(int i= 0;i<min(n,m);i++){
            if(a[i]->val!=b[i]->val){
                return a[i-1];
            }
        }
        // return 0;
        return n<m?a[n-1]:b[m-1];
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