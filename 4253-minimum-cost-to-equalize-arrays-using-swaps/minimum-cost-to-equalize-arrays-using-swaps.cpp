class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1!=n2) return -1;
        map<int,int>totMap;
        map<int,int>mp1;
        map<int,int>mp2;
        int cost=0;
        for(int i=0;i<n1;i++){
            totMap[nums1[i]]++;
            totMap[nums2[i]]++;
        }
        for(auto it:totMap){
            if(it.second%2!=0) return -1;
        }
        for(int i=0;i<n1;i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<n2;i++){
            mp2[nums2[i]]++;
        }
        for(auto it:mp1){
            if(it.second>totMap[it.first]/2){
                cost+=it.second-(totMap[it.first]/2);
            }
        }
        for(auto it:mp2){
            if(it.second>totMap[it.first]/2){
                cost+=it.second-(totMap[it.first]/2);
            }
        }
        return cost/2;
    }
};