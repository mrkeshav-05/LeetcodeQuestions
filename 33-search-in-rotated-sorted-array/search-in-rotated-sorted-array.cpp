class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l <= h){
            int m = (h+l)/2;
            int curr = nums[m];
            if(nums[m] == target){
                return m;
            }
            // left sorted
            if(nums[l] <= curr){
                if(target <= curr && target >= nums[l]){
                    h = m-1;
                }else{
                    l = m+1;
                }
            }else{
                if(target >= curr && target <= nums[h]){
                    l = m+1;
                }else{
                    h = m-1;
                }
            }
        }
        return -1;
    }
};