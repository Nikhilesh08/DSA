class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> mpp[n]; 
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - (long long)nums[j]; 
                
                int count_at_j = 0;
                if(mpp[j].find(diff) != mpp[j].end()) {
                    count_at_j = mpp[j][diff];
                    mpp[i][diff] += count_at_j + 1;
                } else {
                    mpp[i][diff] += 1; 
                }
                ans += count_at_j;
            }
        }
        return ans;
    }
};