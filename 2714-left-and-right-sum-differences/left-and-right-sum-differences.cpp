class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           total+=nums[i];
        }

        vector<int>ans(n,0);
        int prev=0;
        for(int i=0;i<n;i++){
            int suffix=(total-nums[i]-prev);
            int prefix=prev;
            ans[i]=abs(suffix-prefix);
            prev+=nums[i];
        }
        return ans;
    }
};