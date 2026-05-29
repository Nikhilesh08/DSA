class Solution {
public:
    int solve(string &s, int idx, int prevSum, vector<vector<int>> &dp) {
        if (idx >=s.size()) {
            return 1; 
        }
        if (dp[idx][prevSum]!=-1) {
            return dp[idx][prevSum];
        }
        int ans = 0;
        int currentSum = 0;
        
        for (int i =idx;i<s.size();i++) {
            currentSum += (s[i] - '0');
            if (currentSum >=prevSum) {
                ans +=solve(s,i + 1,currentSum,dp);
            }
        }
        return dp[idx][prevSum]=ans;
    }

    int validGroups(string &s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(905, -1));
        return solve(s,0,0,dp);
    }
};