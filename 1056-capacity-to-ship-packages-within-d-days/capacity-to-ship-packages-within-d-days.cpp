class Solution {
public:
    int fun(vector<int> &weights, int limit){
        int ans = 1;
        int tempstr = 0;
        for(int i=0; i<weights.size(); i++){
            if(tempstr + weights[i] <= limit){
                tempstr += weights[i];
            }else{
                ans++;
                tempstr = weights[i];
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = low;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int howmanydays = fun(weights, mid);
            if(howmanydays <= days){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};