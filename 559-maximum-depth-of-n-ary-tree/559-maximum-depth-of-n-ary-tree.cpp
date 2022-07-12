/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxi = 0;
    int maxDepth(Node* root) {
        solve(root, 0);
        return maxi;  
    }
    void solve(Node* &root, int d){
        if(root){
            maxi = max(maxi, d+1);
        }else{
            return;
        }
        for(int i = 0;i<root->children.size();i++){
            solve(root->children[i],d+1);
        }
        
    }
};