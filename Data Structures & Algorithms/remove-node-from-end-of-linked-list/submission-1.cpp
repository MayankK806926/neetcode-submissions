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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        int sz = 0;
        ListNode* tmp = head;
        while(tmp){
            sz++;
            tmp = tmp->next;
        }
        // cout << sz << " ";
        sz--;
        // cout << sz << " ";
        sz -= n;
        // cout << sz << " ";

        if(sz < 0){
            ListNode* node = head->next;
            head = head->next;
            // delete node;
            return head;
        }else{
            ListNode* prev = head;
            ListNode* curr = head->next;
            while(sz--){
                prev = prev->next;
                curr = curr->next;
            }
            cout << prev->val << " " << curr->val << endl;
            ListNode* node = curr->next;
            prev->next = node;
            prev = prev->next;
            curr = curr->next;
            // delete node;

            return head;
        }
    }
};
