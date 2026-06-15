class Solution {
public:
    int n;
    int getNext(vector<vector<int>>& jobs, int currEnd){
        int l=0,r=n-1;
        int next_idx=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=currEnd){
                next_idx=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return next_idx;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        vector<vector<int>>jobs(n,vector<int>(3));
        for(int i=0;i<n;i++){
            jobs[i]={startTime[i],endTime[i],profit[i]};
        }

        sort(jobs.begin(),jobs.end());

        vector<int>dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            int not_pick=dp[idx+1];
            int next_idx=getNext(jobs,jobs[idx][1]);
            int pick=jobs[idx][2]+dp[next_idx];
             dp[idx]=max(pick,not_pick);
        }
        return dp[0];
    }
};