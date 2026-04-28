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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto head : lists){
            if(head) pq.push(head);
        }

        while(!pq.empty()){
            ListNode* node = pq.top();
            temp->next = node;
            temp = temp->next;

            pq.pop();
            if(node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};
