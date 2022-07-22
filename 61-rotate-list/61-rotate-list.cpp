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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        if(!head)return head;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        k = k%n;
        if(k==0)return head;
        curr = head;
        k = n-k;
        while(k>1){
            curr = curr->next;
            k--;
        }
        ListNode* temp = curr->next;
        curr->next = NULL;
        curr = temp;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = head;
        return temp;
        
    }
};