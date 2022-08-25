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
    vector<int> ans;
    void findAtK(TreeNode* root, int k){
        if(k<0 || !root)return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        findAtK(root->left, k-1);
        findAtK(root->right, k-1);
    }
    int find(TreeNode* root, int t, int k){
        if(!root)return -1;
        if(root && root->val==t)return 1;
        int l = find(root->left, t, k);
        int r = find(root->right, t, k);
        if(l!=-1){
            if(l==k){
                ans.push_back(root->val);
                return -1;
            }
            findAtK(root->right,k-l-1);
            return l+1;
            
        }
        if(r!=-1){
            if(r==k){
                ans.push_back(root->val);
                return -1;
            }
            findAtK(root->left,k-r-1);
            return r+1;
        }
        return -1;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        findAtK(target, k);
        find(root, target->val, k);
        return ans;
        
    }
};