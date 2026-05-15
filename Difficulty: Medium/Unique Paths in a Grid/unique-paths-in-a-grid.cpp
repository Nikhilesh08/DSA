class Solution {
  public:
  int n;
  int m;
  int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
      if(i<0 || j<0) return 0;
      if(grid[i][j]==1) return 0;
      if(i==0 && j==0) return 1;
      if(dp[i][j]!=-1) return dp[i][j];
      int left=solve(i,j-1,dp,grid);
      int up=solve(i-1,j,dp,grid);
      return dp[i][j]=left+up;
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,grid);
    }
};