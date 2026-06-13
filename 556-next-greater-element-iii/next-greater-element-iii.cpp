// class Solution {
// public:
//     int nextGreaterElement(int num) {
//         vector<int> str;
//         while(num > 0){
//             int temp = num%10;
//             str.push_back(temp);
//             num = num/10;
//         }
//         reverse(str.begin(), str.end());
//         int n = str.size();
//         int temp = -1;
//         for(int i=n-2; i>=0; i--){
//             if(str[i] < str[i+1]){
//                 temp = i;
//                 break;
//             }
//         }
//         if(temp == -1){
//             return -1;
//         }
//         for(int j=n-1; j>temp; j--){
//             if(str[temp] < str[j]){
//                 swap(str[temp], str[j]);
//             }
//         }
//         int ans = str[0];
//         for(int i=1; i<n; i++){
//             ans = ans*10;
//             ans += str[i];
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int nextGreaterElement(int a) {
        string s=to_string(a);
        int n=s.length();
        int index=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<s[i+1])
            {
                index=i;
                break;
            }
        }
        if(index==-1)return -1;
        int mini=INT_MAX;
        int start=-1;
        for(int i=index+1;i<n;i++)
        {
            if(s[i]>s[index]&&s[i]-s[index]<=mini)
            {
                mini=s[i]-s[index];
                start=i;
            }
        }
        swap(s[index],s[start]);
        
        sort(s.begin()+index+1,s.end());
        long long num = stoll(s);
        if(num>INT_MAX) return -1;
        return (int)num;
    }
};