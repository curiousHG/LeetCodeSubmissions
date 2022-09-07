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
class BSTIterator {
public:
    vector<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        st.push_back(root);
    }
    
    int next() {
        TreeNode* t = st.back();
        while(t->left){
            if(t->left){
                st.push_back(t->left);
                t->left = NULL;
            }
            t = st.back();
        }
        int r = t->val;
        st.pop_back();
        if(t->right){
            st.push_back(t->right);
        }
        return r;
        
    }
    
    bool hasNext() {
        if(st.size()>0)return true;
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */