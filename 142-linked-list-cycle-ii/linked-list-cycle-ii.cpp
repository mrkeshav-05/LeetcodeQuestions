/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        // if(head->next == NULL) return 0;
        unordered_map<ListNode*, int> mp;
        ListNode* curr = head;
        int pos = 0;
        while(curr != NULL){
            if(mp.find(curr) == mp.end()){
                mp[curr] = curr->val;
                curr = curr->next;
            }else{
                return curr;
            }
        }
        return NULL;
    }
};