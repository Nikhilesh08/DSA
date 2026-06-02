class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landDuration.size(),m=waterDuration.size();
        int landEnd=INT_MAX,waterEnd=INT_MAX;
        int ans1=INT_MAX,ans2=INT_MAX;
        for(int i=0;i<n;i++){
            landEnd=min(landEnd,(landStartTime[i]+landDuration[i]));
        }
        for(int i=0;i<m;i++){
            waterEnd=min(waterEnd,(waterStartTime[i]+waterDuration[i]));
        }
        for(int i=0;i<m;i++){
           int waterSt=max(waterStartTime[i],landEnd);
           ans1=min(ans1,waterSt+waterDuration[i]);
        }

         for(int i=0;i<n;i++){
            int landSt=max(landStartTime[i],waterEnd);
           ans2=min(ans2,landSt+landDuration[i]);
        }
        
        return min(ans1,ans2);
    }
};