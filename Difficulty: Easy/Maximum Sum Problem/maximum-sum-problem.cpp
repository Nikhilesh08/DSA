class Solution {
  public:
    int solve(int n){
        if(n<1) return 0;
        int breaks=solve(n/2)+solve(n/3)+solve(n/4);
        int not_break=n;
        return max(breaks,not_break);
    }
    int maxSum(int n) {
        // code here.
        return solve(n);
    }
};