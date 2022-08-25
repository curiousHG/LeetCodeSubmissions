/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(!root)return root;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* prev = NULL;
            for(int i=0;i<n;i++){
                if(!prev){
                    prev = q.front();
                }else{
                    prev->next = q.front();
                    prev = q.front();
                }
                if(prev->left)q.push(prev->left);
                if(prev->right)q.push(prev->right);
                q.pop();
            }
        }
        return root;
        
    }
};