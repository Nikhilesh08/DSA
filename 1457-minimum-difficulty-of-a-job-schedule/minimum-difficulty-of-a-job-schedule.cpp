class Solution {
public:
    int solve(int idx, int d, vector<vector<int>>& dp, vector<int>& jobDifficulty) {
        if (d == 0) {
            int maxi = jobDifficulty[0];
            for (int i = 1; i <= idx; i++) {
                maxi = max(maxi, jobDifficulty[i]);
            }
            return maxi;
        }  
        if (dp[idx][d] != -1) return dp[idx][d];
        int maxi = 0; 
        int ans = 1e9; 
        for (int i = idx; i >= d; i--) {
            maxi = max(maxi, jobDifficulty[i]);
            ans = min(ans, maxi + solve(i - 1, d - 1, dp, jobDifficulty));
        }
        return dp[idx][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1; 
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return solve(n - 1, d - 1, dp, jobDifficulty);
    }
};