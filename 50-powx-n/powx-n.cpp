class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        double ans = 1;
        if(n > 0){
            if(n % 2 == 0) return myPow(x*x, n/2);
            else return (x*myPow(x, n-1));
        }else{
            if(n == INT_MIN && x == 1.0) return 1.0;
            if(n == INT_MIN && x == -1.0) return 1.0;
            if(n == INT_MIN) return 0.0;
            else return 1.0/(myPow(x, -1*n));
        }
    }
};