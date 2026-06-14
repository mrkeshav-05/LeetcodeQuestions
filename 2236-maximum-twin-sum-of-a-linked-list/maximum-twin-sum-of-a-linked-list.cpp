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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
        int max = INT_MIN;
        int n = v.size();
        for(int i=0; i<v.size()/2; i++){
            if(v[i]+v[n-i-1] > max){
                max = v[i]+v[n-i-1];
            }
        }
        return max;
    }
};