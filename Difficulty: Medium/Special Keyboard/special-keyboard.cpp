class Solution {
  public:
  int solve(int ind,vector<int>&dp){
      if(ind<=6) return ind;
      if(dp[ind]!=-1) return dp[ind];
      int maxA=0;
      for(int j=1;j<=ind-3;j++){
         int currA=solve(j,dp)*(ind-j-1);
         maxA=max(maxA,currA);
      }
      return dp[ind]=maxA;
  }
    int optimalKeys(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};