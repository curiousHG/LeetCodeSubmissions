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
    ListNode* middleNode(ListNode* head) {
        int k = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            k++;
        }
        cur = head;
        k = k/2;
        while(k--)cur = cur->next;
        return cur;
    }
};