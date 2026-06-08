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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* curr = head;
        ListNode* nx = head->next;
        while(nx != NULL){
            if(curr->val == nx->val){
                ListNode* temp = nx;
                nx = nx->next;
                curr->next = nx;
                delete temp;
            }else{
                curr = nx;
                nx = nx->next;
            }
        }
        return head;
    }
};