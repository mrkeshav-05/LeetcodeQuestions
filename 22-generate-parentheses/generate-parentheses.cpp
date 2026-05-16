class Solution {
public:
    void generate(vector<string> &v, string s, int open, int close, int n){
        if(s.size() == 2*n){
            v.push_back(s);
        }//base condition
        if(open < n){
            s.push_back('(');
            generate(v, s, open+1, close, n);
            s.pop_back();
        }
        if(close < n && close < open){
            s.push_back(')');
            generate(v, s, open, close+1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate(v, "", 0, 0, n);
        return v;
    }
};