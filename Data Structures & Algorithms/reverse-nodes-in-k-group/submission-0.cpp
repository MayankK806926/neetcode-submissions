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
        ListNode* tmp = head;
        int cnt = 0;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = head;
        ListNode* newHead = NULL;
        ListNode* gt = NULL;
        int tot = cnt / k;

        while(tot--){
            ListNode* gs = curr;
            prev = NULL;
            for(int i=0;i<k;++i){
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            if(newHead == NULL) newHead = prev;
            if(gt) gt->next = prev;

            gt = gs;
        }

        gt->next = curr;
        return newHead;
    }
};
