/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = new ListNode();
        ListNode* temp2 = new ListNode();
        ListNode* head1 = temp;
        ListNode* head2 = temp2;
        ListNode* cur = head;
        while(cur){
            if(cur->val<x){
                temp->next = new ListNode(cur->val);
                temp = temp->next;
            }else{
                temp2->next = new ListNode(cur->val);
                temp2 = temp2->next;
                
            }
            cur = cur->next;
        }
        temp->next = head2->next;
        return head1->next;
        
        
    }
};