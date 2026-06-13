class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        int pivot = -1;

        for(int i = s.size()-2; i >= 0; i--){
            if(s[i] < s[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1) return -1;

        int idx = pivot + 1;

        for(int i = pivot + 1; i < s.size(); i++){
            if(s[i] > s[pivot] && s[i] <= s[idx]){
                idx = i;
            }
        }

        swap(s[pivot], s[idx]);

        sort(s.begin() + pivot + 1, s.end());

        long long num = stoll(s);

        return num > INT_MAX ? -1 : (int)num;
    }
};