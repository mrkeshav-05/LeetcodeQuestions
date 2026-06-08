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
        ListNode* check = head;
        for(int i=0; i<k; i++){
            if(check == NULL) return head;
            check = check->next;
        }
        int cnt = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextptr = NULL;
        while(cnt < k){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            cnt++;
        }
        if(nextptr != NULL){
            head->next = reverseKGroup(nextptr, k);
        }
        return prev;
    }
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         // if head is NULL
//         if(head == NULL) return head;
//         ListNode* check = head;
//         for(int i=0; i<k; i++){
//             if(check == NULL) return head;
//             check = check->next;
//         }
//         // reverse the elements;
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         ListNode* next = NULL;
//         int cnt = 0;
//         while(cnt < k){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//             cnt++;
//         }
//         if(next != NULL){
//             head->next = reverseKGroup(next, k);
//         }
//         return prev;
//     }
// };