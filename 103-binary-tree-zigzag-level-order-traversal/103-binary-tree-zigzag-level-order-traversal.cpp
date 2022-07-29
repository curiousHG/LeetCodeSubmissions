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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int d;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>> que;
        if(!root)return ans;
        que.push(make_pair(root,0));
        while(!que.empty()){
            pair<TreeNode*,int> cur = que.front();
            TreeNode* n = cur.first;
            d = cur.second;
            que.pop();
            if(d==ans.size()){
                if(d>0 && d%2==0){
                    reverse(ans.back().begin(),ans.back().end());
                // for(int j:ans.back())cout<<j<<" ";
                // cout<<endl;
                }
                ans.push_back(vector<int>());
            }
            ans.back().push_back(n->val);
            if(n->left){
                que.push(make_pair(n->left,d+1));
            }
            if(cur.first->right){
                que.push(make_pair(n->right,d+1));
            }
        }
        if(d%2==1)reverse(ans.back().begin(),ans.back().end());
        return ans;
    }
};