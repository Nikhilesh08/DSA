class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int maxi=INT_MIN;
        for(auto num:nums){
            mpp[num]++;
            maxi=max(maxi,num);
        }
        if(mpp[maxi]!=2) return false;
        for(int i=1;i<=maxi-1;i++){
            if(mpp[i]>1 || mpp[i]==0) return false;
        }
        return true;
    }
};