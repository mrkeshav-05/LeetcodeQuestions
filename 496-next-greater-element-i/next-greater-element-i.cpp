class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            st.push(nums2[i]);
        }
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums2[i]] = i;
        }
        int n1 = nums1.size();
        vector<int> ans(n1);
        for(int i=0; i<n1; i++){
            ans[i] = nge[mp[nums1[i]]];
        }
        return ans;
    }
};
// 4 1 2
// 1 3 4 2