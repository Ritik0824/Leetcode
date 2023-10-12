class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = (long long) dividend, b = (long long)divisor;
        if (a == INT_MIN and b == -1) return INT_MAX;
        if (a == INT_MIN and b == 1) return INT_MIN;
        bool flg = (a > 0) == (b > 0) ? true : false;
        a = abs(a);
        b = abs(b);
        long long ans =0, temp = 0;
        for (int i = 31 ; i >= 0 ; i--){
            if (temp + ( b << i ) <= a){
                temp+= (b<<i);
                ans+= (1<<i);
            }
        }
        if (!flg) ans = -ans;
        return ans;
    }
};