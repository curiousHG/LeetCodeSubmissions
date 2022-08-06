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
    void solve(int val, int d,TreeNode* root){
        if(!root)return;
        if(d==1){
            TreeNode* nl = new TreeNode(val);
            TreeNode* nr = new TreeNode(val);
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = nl;
            nl->left = l;
            root->right = nr;
            nr->right = r;
            return;
        }
        solve(val, d-1, root->left);
        solve(val, d-1, root->right);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* n = new TreeNode(val);
            n->left=root;
            return n;
        }
        solve(val, depth-1, root);
        return root;
        
    }
};