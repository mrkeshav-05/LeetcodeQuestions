class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int firstoccu = -1;
        int l = 0; int h = n-1;
        while(l <= h){
            int m = (h+l)/2;
            if(nums[m] == target){
                firstoccu = m;
                h = m-1;
            }else if(nums[m] > target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        int lastoccu = -1;
        l = 0; h = n-1;
        while(l <= h){
            int m = (h+l)/2;
            if(nums[m] == target){
                lastoccu = m;
                l = m+1;
            }else if(nums[m] > target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        return {firstoccu, lastoccu};
        // return {-1, -1};
    }
};