class Solution {
public:
    int n;
    
    int solve(int idx, string &s, vector<int>& dp) {
        if (idx == n) return 1;
        if (s[idx] == '0') return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int take_curr = solve(idx + 1, s, dp);
        
        int take_till_next = 0;
        if (idx + 1 < n && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            take_till_next = solve(idx + 2, s, dp);
        }
        
        return dp[idx] = take_curr + take_till_next;
    }
    
    int countWays(string &digits) {
        n = digits.size();
        vector<int> dp(n + 1, -1);
        return solve(0, digits, dp);
    }
};