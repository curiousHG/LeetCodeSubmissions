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
    int ans=0;
    int minCameraCover(TreeNode* root) {
        if(!root)return 0;
        if(check_leave(root))return 1;
        int val = solve(root);
        if(val==-1)ans++;
        return ans;
    }
    bool check_leave(TreeNode* root){
        if(!root)return false;
        return root->left==NULL && root->right==NULL;
    }
    int solve(TreeNode* root){
        if(!root)return 0;
        if(check_leave(root))return -1;
        int l = solve(root->left), r = solve(root->right);
        // cout<<l<<" "<<r<<endl;
        if(l==-1 || r==-1){
            ans++;
            return root->val = 2;
        }
        if(l==2||r==2){
            return root->val=1;
        }
        if(l==1 || r==1){
            return root->val = -1;
        }
        return 0;
    }
};