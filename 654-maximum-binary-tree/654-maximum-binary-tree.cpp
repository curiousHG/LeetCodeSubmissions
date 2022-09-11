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
    TreeNode* solve(int i, int j, vector<int>& nums){
        if(j<i)return NULL;
        int k = i, maxi = nums[i],ind = i;
        while(k<=j){
            if(nums[k]>maxi){
                maxi = nums[k];
                ind = k;
            }
            k++;
        }
        TreeNode* left = solve(i, ind-1,nums);
        TreeNode* right = solve(ind+1, j,nums);
        TreeNode* ret = new TreeNode(maxi);
        ret->left = left;
        ret->right = right;
        return ret;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0,nums.size()-1, nums);
    }
};