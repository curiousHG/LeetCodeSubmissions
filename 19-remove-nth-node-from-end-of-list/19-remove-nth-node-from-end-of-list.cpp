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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            l++;
        }
        int f = l-n;
        if(f==0)return head->next;
        curr = head;
        ListNode* prev = NULL;
        while(f>0 && curr){
            prev = curr;
            curr = curr->next;
            f--;
        }
        prev->next = curr->next;
        return head;
    }
};