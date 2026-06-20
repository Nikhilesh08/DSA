class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int min_idx=-1,max_idx=-1,wro_idx=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxK){
                max_idx=i;
            }
            if(nums[i]==minK){
                min_idx=i;
            }
            if(nums[i]<minK || nums[i]>maxK){
                wro_idx=i;
            }

            long long small=min(min_idx,max_idx);
            long long temp=small-wro_idx;
            ans+=(temp<0)?0:temp;
       }
       return ans;
    }
};