class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it:mp){
            char c = it.first;
            int freq = it.second;
            pq.push({freq, c});
        }
        string ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int freq = it.first;
            int c = it.second;
            for(int i=1; i<=freq; i++){
                ans += c;
            }
        }
        return ans;
    }
};