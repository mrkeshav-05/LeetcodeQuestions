class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map to store num, freq.
        unordered_map<int,int> freqMap ;

        //fill the map
        for(int n : nums){
            freqMap[n]++ ;
        }
        
        //bucket to group same freq elements
        vector<vector<int>> bucket(nums.size() + 1);

        //fill the bucket
        for(auto &entry : freqMap){
            int num = entry.first ;
            int freq = entry.second ;
            bucket[freq].push_back(num) ;
        }

        //output vector
        vector<int> ans ;
        
        //reverse loop n to 1
        for(int freq = bucket.size()-1 ; freq >= 0 && ans.size() < k ; freq--){
            //if bucket is not empty
            if(!bucket[freq].empty()){
                for(int num : bucket[freq]){
                    ans.push_back(num) ; //push in ans vector

                    //when k value reached
                    if(ans.size() == k){
                        break ;
                    }

                }
            }
       
        }

        return ans ;
    }
};