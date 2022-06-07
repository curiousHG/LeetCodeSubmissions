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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0;i<lists.size();i++){
            while(lists[i]){
                int m = lists[i]->val;
                q.push(m);
                lists[i] = lists[i]->next;
            }
        }
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(!q.empty()){
            int val = q.top();
            curr->next = new ListNode(val);
            q.pop();
            curr = curr->next;
            // cout<<val<<" ";
        }
        // cout<<endl;
        return head->next;
    }
};