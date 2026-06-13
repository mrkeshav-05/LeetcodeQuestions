class Solution {
public:
    bool abletomake(vector<int>& bloomDay, int m, int k, int day){
        int n = bloomDay.size();
        int cnt = 0;
        int bou = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt == k){
                bou++;
                cnt=0;
            }
        }
        if(bou >= m){
            return true;
        }else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minn = *min_element(bloomDay.begin(), bloomDay.end());
        int maxx = *max_element(bloomDay.begin(), bloomDay.end());
        int low = minn, high = maxx;
        if(m > bloomDay.size()/k){
            return -1;
        }
        while(low <= high){
            int mid = (high + low ) >> 1;
            bool flag = abletomake(bloomDay, m, k, mid);
            if(flag){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};