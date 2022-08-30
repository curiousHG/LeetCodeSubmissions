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
    vector<vector<string>> lev;
    int diff(string s1, string s2){
        int n = s1.size();
        int v = 0;
        for(int i = 0;i<n;i++){
            v*=2;
            if(s1[i]=='1' && s2[i]=='1'){
            }else if(s1[i]=='1'){
                v+=1;
            }else if(s2[i]=='1'){
                v-=1;
            }
        }
        // cout<<s1<<" "<<s2<<" "<<v<<endl;
        return v;
        
    }
    void solve(TreeNode* root,string path, int l){
        if(!root)return;
        if(lev.size()==l+1)lev.push_back(vector<string>());
        if(root->left){
            lev[l+1].push_back(path+'0');
            solve(root->left, path+'0',l+1);
        }
        if(root->right){
            lev[l+1].push_back(path+'1');
            solve(root->right, path+'1',l+1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        lev.push_back(vector<string>(1,"0"));
        solve(root, "",0);
        int maxi = 0;
        for(int i = 0;i<lev.size();i++){
            vector<string> k = lev[i]; 
            if(k.size()==0)continue;
            maxi = max(maxi, diff(k.back(),k.front())+1);
        }
        return maxi;
    }
};