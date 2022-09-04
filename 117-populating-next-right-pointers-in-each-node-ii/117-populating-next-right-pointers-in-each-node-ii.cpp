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
        Node* cur = root;
        queue<Node*> q;
        if(!root)return root;
        q.push(root);
        while(!q.empty()){
            Node* p = NULL;
            int n = q.size();
            for(int i= 0;i<n;i++){
                Node* t = q.front();
                q.pop();
                if(p!=NULL){
                    p->next = t;
                    p = p->next;
                }else{
                    p = t;
                }
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return root;
    }
};