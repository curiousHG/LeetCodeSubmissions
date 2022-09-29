/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        Node* cur = head;
        Node* last;
        while(cur){
            // cout<<cur->val<<" ";
            if(cur->child){
                Node* right = cur->next;
                cur->child->prev = cur;
                Node* end = solve(cur->child);
                cur->next = cur->child;
                cur->child = NULL;
                end->next = right;
                if(right){
                    right->prev = end;
                    cur = right;
                }
            }
            if(!cur->next)last = cur;
            cur = cur->next;
        }
        return last;
        
    }
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};