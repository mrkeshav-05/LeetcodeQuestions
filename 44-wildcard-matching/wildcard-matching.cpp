class Solution {
public:
    bool fun(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        // Base case: Both empty
        if(i < 0 && j < 0) return true;
        // Base case: Pattern empty but string not
        if(j < 0 && i >= 0) return false;
        // Base case: String empty but pattern not
        if(i < 0 && j >= 0){
            // All remaining characters in pattern must be '*'
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // Match logic
        if(p[j] == s[i] || p[j] == '?'){
            return dp[i][j] = fun(s, p, i-1, j-1, dp);
        }
        
        if(p[j] == '*'){
            // '*' matches empty sequence (j-1) OR matches one/more chars (i-1)
            return dp[i][j] = fun(s, p, i, j-1, dp) || fun(s, p, i-1, j, dp);
        }
        
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        // dp[i][j] means s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle cases where s is empty, but p contains '*'
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[n][m];
        // return fun(s, p, n-1, m-1, dp);
    }
};