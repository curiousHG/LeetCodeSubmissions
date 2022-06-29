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
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> m;
        for(int p = 1;p<=n;p+=2){
            vector<TreeNode*> arr;
            TreeNode* k;
            k = new TreeNode();
            for(int i = 1;i<=p-2;i+=2){
                for(TreeNode* l:m[i]){
                    for(TreeNode* r:m[p-1-i]){
                        k = new TreeNode();
                        k->left = l;
                        k->right = r;
                        arr.push_back(k);
                    }
                }
            }
            if(p==1)arr.push_back(k);
            m[p] = arr;
            // return m[p];
        }
        return m[n];
    }

};