class Solution {
  public:
    int solve(int idx, int last, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (dp[idx][last] != -1) return dp[idx][last];
        
        int points = 0; 
        
        if (idx == 0) {
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    points = max(points, mat[idx][task]);
                }
            }
            return dp[idx][last] = points;
        }
        
        for (int task = 0; task < 3; task++) {
            if (task != last) {
               points = max(points, mat[idx][task] + solve(idx - 1, task, mat, dp));
            }
        }
        
        return dp[idx][last] = points;
    }
    
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n - 1, 3, mat, dp);
    }
};