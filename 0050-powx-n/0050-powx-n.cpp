class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1.0;

        // Handle negative exponent by converting it to positive
        if (nn < 0) {
            nn = -nn;
        }

        // Binary exponentiation algorithm
        while (nn) {
            if (nn % 2 == 1) {
                // If current power is odd, multiply the result with x
                ans = ans * x;
                nn = nn - 1;
            } else {
                // If current power is even, square the x and reduce the power
                x = x * x;
                nn = nn / 2;
            }
        }

        // Handle negative exponent by taking reciprocal of the result
        if (n < 0) {
            ans = double(1.0) / double(ans);
            return ans;
        } else {
            return ans;
        }
    }
};