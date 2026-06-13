class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.size();
        for(int i=0 ; i<n; i++){
            if(s[i] != ' '){
                string temp = "";
                for(int j=i;j<n;j++){
                    if(s[j] == ' '){
                        v.push_back(temp);
                        i = j;
                        break;
                    }
                    if(j == n-1){
                        temp += s[j];
                        v.push_back(temp);
                        i = j;
                    }
                    
                    temp += s[j];
                }
            }
        }
        reverse(v.begin(), v.end());
        string ans = "";
        for(int i=0; i<v.size(); i++){
            if(i==v.size()-1){
                ans += v[i];
            }else{
                ans += v[i]+' ';
            }
        }
        return ans;
    }
};