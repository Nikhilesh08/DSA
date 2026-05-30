class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long  sum1=nums[0],sum2=0;
        bool split=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                sum1+=nums[i+1];
            }
            else if(nums[i]>nums[i+1] && split){
                sum2=sum2+nums[i]+nums[i+1];
                split=false;
            }
            else{
                sum2+=nums[i+1];
            }
        }
        if(sum2==sum1) return -1;
        return sum2>sum1;
    }
};