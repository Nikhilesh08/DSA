class Solution {
public:
    int solve(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind == 0) return 0;
        if (ind == 1) return 0;
        if (dp[ind] != -1) return dp[ind];
        int first = cost[ind-1]+solve(ind - 1, cost, dp);
        int second = cost[ind-2]+solve(ind - 2, cost, dp);
        return dp[ind] =min(first, second);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n,cost,dp);
    }
};