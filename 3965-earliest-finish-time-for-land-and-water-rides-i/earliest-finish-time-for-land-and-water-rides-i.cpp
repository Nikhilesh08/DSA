class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landDuration.size(),m=waterDuration.size();
        int landEnd=INT_MAX,waterEnd=INT_MAX;
        int dura1=INT_MAX,dura2=INT_MAX;
        for(int i=0;i<n;i++){
            landEnd=min(landEnd,(landStartTime[i]+landDuration[i]));
        }
        for(int i=0;i<m;i++){
            waterEnd=min(waterEnd,(waterStartTime[i]+waterDuration[i]));
        }
        for(int i=0;i<m;i++){
            if(waterStartTime[i]<=landEnd){
                dura1=min(dura1,waterDuration[i]);
            }
            else{
                dura1=min(dura1,(waterStartTime[i]-landEnd+waterDuration[i]));
            }
        }

         for(int i=0;i<n;i++){
            if(landStartTime[i]<=waterEnd){
                dura2=min(dura2,landDuration[i]);
            }
            else{
                dura2=min(dura2,(landStartTime[i]-waterEnd+landDuration[i]));
            }
        }
        
        return min(landEnd+dura1,waterEnd+dura2);
    }
};