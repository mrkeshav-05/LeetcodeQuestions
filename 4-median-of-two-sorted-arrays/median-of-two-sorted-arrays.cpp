class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> v;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            v.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            v.push_back(nums2[j]);
            j++;
        }
        int k = n+m;
        if(k%2==0){
            return (double)(v[k/2-1]+v[k/2])/2;
        }else{
            return (v[k/2]);
        }




















        // vector<int> v;
        // int i = 0;
        // int j = 0;
        // while(i < nums1.size() && j < nums2.size()){
        //     if(nums1[i]<=nums2[j]){
        //         v.push_back(nums1[i]);
        //         i++;
        //     }else{
        //         v.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // while(i<nums1.size()){
        //     v.push_back(nums1[i]);
        //     i++;
        // }
        // while(j<nums2.size()){
        //     v.push_back(nums2[j]);
        //     j++;
        // }
        // int n = v.size();
        // if(n%2==0){
        //     return (double)(v[n/2-1]+v[n/2])/2;
        // }else{
        //     return (v[n/2]);
        // }
    }
};