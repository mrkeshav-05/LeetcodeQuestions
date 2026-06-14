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
    ListNode* reverse(ListNode* head){
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverse(slow);
        ListNode* temp2 = head2;
        ListNode* temp1 = head;
        int maxx = INT_MIN;
        while(temp2 != NULL && temp1 != NULL){
            if(temp1->val + temp2->val > maxx){
                maxx = temp1->val + temp2->val;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return maxx;
    }
};