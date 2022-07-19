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
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode* a = head;
        ListNode* b = head;
        while(true){
            a = a->next;
            // if(a==NULL)return false;
            if(b && b->next)b = b->next->next;
            else return false;
            // cout<<a->val<<" "<<b->val<<endl;
            if(a==b)return true;
            
        }
    }
};