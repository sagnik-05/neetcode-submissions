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
        ListNode* curr = head;
        int group = 0;
        while(curr && group < k){
            curr = curr->next;
            group++;
        }

        if(group == k){
            curr = reverseKGroup(curr, k);
            while(group--){
                ListNode* next = head->next; // store next
                head->next = curr;           // reverse link
                curr = head;                 // move curr forward
                head = next;                 // move head forward
            }
            head = curr;
        }
        return head;
    }
};
