class Solution {
public:
    int fun(string word1, string word2, int n, int m, int i, int j, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]) return dp[i][j] = 0 + fun(word1, word2, n, m, i-1, j-1, dp);
        return dp[i][j] = 1+min(fun(word1, word2, n, m, i-1, j-1, dp), min(fun(word1, word2, n, m, i-1, j, dp), fun(word1, word2, n, m, i, j-1, dp)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=m; i++){
            dp[0][i] = i;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0+dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
        // return fun(word1, word2, n, m, n-1, m-1, dp);
    }
};