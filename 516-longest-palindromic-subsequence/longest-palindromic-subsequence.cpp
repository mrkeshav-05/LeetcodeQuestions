class Solution {
public:
    int fun(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1+fun(s1, s2, i-1, j-1, dp);
        }
        return dp[i][j] = max(fun(s1, s2, i-1, j, dp), fun(s1, s2, i, j-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        // return fun(s, s2, n-1, n-1, dp);
    }
};