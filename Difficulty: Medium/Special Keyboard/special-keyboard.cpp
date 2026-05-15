class Solution {
public:
    int optimalKeys(int n) {
        if (n <= 6) {
            return n;
        }
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }
        for (int i = 7; i <= n; i++) {
            dp[i] = max({
                dp[i - 3] * 2, 
                dp[i - 4] * 3, 
                dp[i - 5] * 4
            });
        }
        return dp[n];
    }
};