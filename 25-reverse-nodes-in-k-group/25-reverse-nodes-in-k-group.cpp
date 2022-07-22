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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode* curr = head;
        ListNode* rH = NULL;
        ListNode* prevEND = NULL;
        int l = k;
        while(true){
            ListNode* temp = curr;
            ListNode* next;
            while(l>1&&temp){
                temp = temp->next;
                l--;
                
            }
            if(!temp){
                if(!rH)rH = head;
                else{
                    prevEND->next = curr;
                }
                break;
            }
            l = k;
            if(!temp){
                // cout<<l<<endl;
                break;
            }
            next = temp->next;
            temp->next = NULL;
            
            vector<ListNode*> revN = rev(curr);
            curr = next;
            if(!rH){
                rH = revN[1];
            }else{
                prevEND->next = revN[1];   
            }
            prevEND = revN[0];
            // break;
            
        }
        return rH;
    }
    vector<ListNode*> rev(ListNode* head){
        vector<ListNode*> r;
        ListNode* curr = head;
        ListNode* prev = NULL;
        r.push_back(curr);
        while(curr){
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        
        r.push_back(prev);
        
        return r;
    }
};