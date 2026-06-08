class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n,0);
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                cnt1++;
            }
            else if(nums[i]==pivot){
                cnt2++;
            }
        }
        int low=0;
        int mid=cnt1;
        int high=cnt1+cnt2;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[low]=nums[i];
                low++;
            }
            else if(nums[i]==pivot){
                ans[mid]=nums[i];
                mid++;
            }
            else{
              ans[high]=nums[i];
                high++;
            }
        }
        return ans;

    }
};