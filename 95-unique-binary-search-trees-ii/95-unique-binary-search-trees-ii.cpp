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
    vector<TreeNode*> solve(int i, int j){
        vector<TreeNode*> ans;
        if(i>j){
            ans.push_back(NULL);
            return ans;
        }
        if(i==j){
            TreeNode* n = new TreeNode(i);
            ans.push_back(n);
            return ans;
        }
        for(int k = i;k<=j;k++){
            vector<TreeNode*> left = solve(i, k-1);
            vector<TreeNode*> right = solve(k+1, j);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* n = new TreeNode(k);
                    n->left = l;
                    n->right = r;
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};