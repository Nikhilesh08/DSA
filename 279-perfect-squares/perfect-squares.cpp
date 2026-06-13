class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        
        int min_squares = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int current_squares = 1 + solve(n - (i * i));
            min_squares = min(min_squares, current_squares);
        }
        return dp[n] = min_squares;
    }
    
    int numSquares(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};