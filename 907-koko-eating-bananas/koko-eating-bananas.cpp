class Solution {
public:
    // Use long long to prevent overflow when summing hours
    long long search(vector<int> &piles, int mid) {
        long long totalHours = 0;
        for(int i : piles) {
            // Using long long here ensures (i + mid - 1) doesn't overflow
            totalHours += (long long)(i + mid - 1) / mid;
        }
        return totalHours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while(low <= high) {
            int mid = low + (high - low) / 2; // Prevents overflow of (low + high)
            if(search(piles, mid) <= (long long)h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};