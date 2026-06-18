class Solution {
public:
    vector<int> travel;
    vector<int> dp; 
    
    int solve(int idx, vector<int>& days, vector<int>& costs) {
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int ans = INT_MAX;
        for(int i = 0; i < 3; i++){
            auto it = upper_bound(days.begin(), days.end(), days[idx] + travel[i] - 1);
            if(it == days.end()){
                ans = min(ans, costs[i]);
                continue;
            }
            int next_idx = it - days.begin();
            ans = min(ans, costs[i] + solve(next_idx, days, costs));
        }
        
        return dp[idx] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        travel = {1, 7, 30}; 
        dp.assign(days.size(), -1); 
        return solve(0, days, costs);
    }
};