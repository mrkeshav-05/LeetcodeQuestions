class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for(auto i: piles){
            pq.push(i);
        }
        while(k > 0){
            int temp = pq.top();
            pq.pop();
            if(temp%2 == 0){
                temp = temp/2;
            }else{
                temp = temp/2+1;
            }
            pq.push(temp);
            k--;
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};