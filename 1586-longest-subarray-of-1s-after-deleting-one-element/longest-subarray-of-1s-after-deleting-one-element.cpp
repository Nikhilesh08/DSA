class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0,curr_streak=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maxi=max(maxi,prev+curr_streak);
                prev=curr_streak;
                curr_streak=0;
            }
            else{
                curr_streak++;
            }
        }
        maxi=max(maxi,prev+curr_streak);
        if(curr_streak==nums.size()) return nums.size()-1; // all ones
        return maxi;
    }
};