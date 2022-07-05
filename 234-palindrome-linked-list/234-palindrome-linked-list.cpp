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
    bool isPalindrome(ListNode* head) {
        ListNode* h1 = head;
        if(!h1->next)return true;
        ListNode* h2 = head;
        int n = 0;
        while(h2 &&h2->next){
            h1 = h1->next;
            h2 = h2->next->next;
            n++;
        }
        if(h2 && !h2->next)h1->next;
        ListNode* prev = NULL;
        ListNode* curr = h1;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
        }
        while(n--){
            // cout<<prev->val<<" "<<head->val;
            if(head->val!=prev->val)return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
        
        
    }
};