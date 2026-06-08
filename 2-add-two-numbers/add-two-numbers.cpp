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
    ListNode* reverseLL(ListNode* head){
        if(!head) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return l1;
        // l1 = reverseLL(l1);
        // l2 = reverseLL(l2);
        int carry = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        while(h1 != NULL || h2 != NULL){
            int sum = carry;
            if(h1 != NULL){
                sum += h1->val;
                h1 = h1->next;
            }
            if(h2 != NULL){
                sum += h2->val;
                h2 = h2->next;
            }
            carry = sum/10;
            sum = sum%10;
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;
        }
        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = curr->next;
        }
        return result->next;
    }
};