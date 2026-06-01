class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int minn = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[mid]){
                minn = min(minn, nums[low]);
                low = mid+1;
            }else{
                minn = min(minn, nums[mid]);
                high = mid-1;
            }
        }
        return minn;
    }
};