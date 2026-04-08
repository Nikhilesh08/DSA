class Solution {
public:
    void solve(vector<int>& nums, vector<int>& op) {
        int l = op[0];
        int r = op[1];
        int k = op[2];
        int v = op[3];
        int MOD = 1000000007;
        for(int i = l; i <= r; i += k) {
            nums[i] = (1LL * nums[i] * v) % MOD; 
        }
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        for(int i = 0; i < n; i++) {
            solve(nums, queries[i]);
        }
        int finalXor = 0;
        for (int num : nums) {
            finalXor ^= num;
        }
        return finalXor;
    }
};