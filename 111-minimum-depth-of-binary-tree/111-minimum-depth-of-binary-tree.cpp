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
    int minDepth(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        queue<pair<TreeNode*, int>> pq;
        if(!root)return 0;
        pq.push(make_pair(root, 1));
        while(!pq.empty()){
            pair<TreeNode*, int> a = pq.front();
            pq.pop();
            if(!a.first->left && !a.first->right){
                return a.second;
            }
            if(a.first->left)pq.push(make_pair(a.first->left,a.second+1));
            if(a.first->right)pq.push(make_pair(a.first->right,a.second+1));
        }
        return 0;
    }
    
};