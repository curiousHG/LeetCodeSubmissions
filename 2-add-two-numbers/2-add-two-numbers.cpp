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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val+l2->val+carry;
            curr->val = sum%10;
            carry = sum/10;
            if(l1->next && l2->next){
                curr->next = new ListNode();
                curr = curr->next;
            }
            l1= l1->next;
            l2 = l2->next;
            
        }
        while(l1){
            int sum = l1->val+carry;
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            if(l1)curr = curr->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val+carry;
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            if(l2)curr = curr->next;
            l2 = l2->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return head;
    }
};