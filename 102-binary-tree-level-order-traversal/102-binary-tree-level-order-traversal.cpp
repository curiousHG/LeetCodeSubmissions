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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        recur(root, 0);
        return ans;
    }
    void recur(TreeNode* curr, int level){
        if(curr){
            if(ans.size()==level){
                ans.push_back(vector<int>());
            }
            ans[level].push_back(curr->val);
            recur(curr->left, level+1);
            recur(curr->right, level+1);
            
        }
    }
};