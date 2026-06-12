class Solution {
public:
    bool canSplit(vector<int> &nums, int mid, int k) {
        int subarrayCount = 1;
        long long currentSum = 0;
        
        for(int num : nums) {
            if(currentSum + num <= mid) {
                currentSum += num;
            } else {
                subarrayCount++;
                currentSum = num;
                if(subarrayCount > k) return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canSplit(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};