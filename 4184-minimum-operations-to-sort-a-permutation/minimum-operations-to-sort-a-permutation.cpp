class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int pos0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }

        bool is_inc = true;
        bool is_dec = true;

        for (int i = 0; i < n; ++i) {
            if ((nums[(i + 1) % n] - nums[i] + n) % n != 1) {
                is_inc = false;
            }
            if ((nums[i] - nums[(i + 1) % n] + n) % n != 1) {
                is_dec = false;
            }
        }

        int ans = INT_MAX;

        if (is_inc) {
            int cost1 = pos0; 
            int cost2 = (pos0 == 0) ? 0 : 2 + n - pos0; 
            ans = min({ans, cost1, cost2});
        }

        if (is_dec) {
            int cost1 = (pos0 + 1) % n + 1; 
            int cost2 = n - pos0;           
            ans = min({ans, cost1, cost2});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};