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
        // Use n and m as dimensions, access via n-1, m-1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fun(s, p, n-1, m-1, dp);
    }
};