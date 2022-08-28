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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dum = new ListNode(0);
        dum->next =head;
        ListNode* prev = dum, *cur = dum->next;
        while(cur && cur->next){
            if(cur->val==cur->next->val){
                while(cur && cur->next && cur->val==cur->next->val){
                    cur = cur->next;
                }
                cur = cur->next;
                prev->next = cur;
            }else{
                cur = cur->next;
                prev = prev->next;
            }
            
            
        }
        return dum->next;
        
    }
};