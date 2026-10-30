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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;
        while(curr1 || curr2 || carry){
            int val1 = curr1 ? curr1->val : 0;
            if(curr1) curr1 = curr1->next;
            int val2 = curr2 ? curr2->val : 0;
            if(curr2) curr2 = curr2->next;

            int num = val1 + val2 + carry;
            carry = num / 10;
            num = num % 10;

            curr->val = num;
            if(curr1 || curr2 || carry){
                curr->next = new ListNode(0);
                curr = curr->next;
            }
        }

        return head;
    }
};
