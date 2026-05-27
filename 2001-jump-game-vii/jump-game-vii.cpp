class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int>dp(n,0);
        dp[0]=1; // if 0 cannot reach,1 can reach
        int count=0;
        for(int i=1;i<s.size();i++){
            if(i-minJump>=0){
                count+=dp[i-minJump];
            }
            if(i-maxJump-1>=0){
                count-=dp[i-maxJump-1];
            }
            if(count>0 && s[i]=='0'){
                dp[i]=1;
            }
        }
        return dp[n-1]==1;
    }
};