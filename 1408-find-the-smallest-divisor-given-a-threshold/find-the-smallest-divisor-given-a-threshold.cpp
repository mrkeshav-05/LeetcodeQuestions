class Solution {
public:
    int fun(vector<int> nums, int mid){
        int ans = 0;
        for(int i:nums){
            if(i%mid == 0){
                ans += ceil(i/mid);
            }else{
                int temp = i/mid;
                ans += 1+temp;
            }
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            int result = fun(nums, mid);
            if(result <= threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};