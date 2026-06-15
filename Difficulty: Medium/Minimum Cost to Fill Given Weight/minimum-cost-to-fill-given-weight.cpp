class Solution {
public:
    int n;
    
    int solve(int idx, vector<int>& cost, int w, vector<vector<int>>& dp) {
        if (w == 0) return 0;
        if (idx == n - 1) {
            if (cost[idx] != -1 && w % (idx + 1) == 0) {
                return (w / (idx + 1)) * cost[idx];
            } else {
                return 1e9;
            }
        }
        if (dp[idx][w] != -1) return dp[idx][w];
        
        int pick = 1e9;
        
        if (cost[idx] != -1 && w >= idx + 1) {
            pick = cost[idx] + solve(idx, cost, w - (idx + 1), dp);
        }
        
        int not_pick = solve(idx + 1, cost, w, dp);
        
        return dp[idx][w] = min(pick, not_pick);
    }
    
    int minimumCost(vector<int>& cost, int w) {
        n = cost.size();
        
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        
        int ans = solve(0, cost, w, dp);
        
        return (ans >= 1e8) ? -1 : ans;
    }
};