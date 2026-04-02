class Solution {
public:
    int solve(vector<vector<int>>& coins, int i, int j, int k, vector<vector<vector<int>>>& dp){
        int m=coins.size();
        int n=coins[0].size();
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && k>0){
                return 0;
            }
            return coins[i][j];
        }
        if(i>=m || j>=n) return INT_MIN;
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
        int take=coins[i][j]+max(solve(coins,i+1,j,k, dp),solve(coins,i,j+1,k, dp));

        int skip=INT_MIN;
        if(coins[i][j]<0 && k>0){
            int skipRight=solve(coins,i,j+1,k-1, dp); 
            int skipDown=solve(coins,i+1,j,k-1, dp);
            skip=max(skipDown,skipRight);
        }
        return dp[i][j][k]=max(take,skip);

    }
    
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(), vector<vector<int>>(coins[0].size(), vector<int>(3, INT_MIN)));
        return solve(coins,0,0,2, dp);
    }
};