class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        int l=0,r=0;
        while(r<nums.size()){
            if(abs(l-r)>k){
                st.erase(nums[l]);
                l++;
            }
            if(st.find(nums[r])!=st.end()){
                return true;
            }
            st.insert(nums[r]);
            r++;
        }
        return false;
    }
};