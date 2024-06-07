class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort the pairs based on their second element
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = pairs.size();
        vector<int> dp(n, 1); // dp[i] will be the maximum chain length ending with pairs[i]

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
