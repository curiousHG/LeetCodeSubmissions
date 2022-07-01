/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* n = node->next;
        while(n->next!=NULL){
            node->val = n->val;
            node = node->next;
            n = n->next;
        }
        node->val = n->val;
        node->next = NULL;
    }
};