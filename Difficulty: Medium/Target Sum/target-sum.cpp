class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // Base cases: 
        // 1. If target is completely out of bounds.
        // 2. If (totalSum + target) is odd, we can't divide it into integers.
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }
        
        // This is the target sum we need to find using a subset of the array
        int subsetSum = (totalSum + target) / 2;
        
        // dp[i] will store the number of ways to make the sum 'i'
        vector<int> dp(subsetSum + 1, 0);
        
        // There is 1 way to make a sum of 0: pick no elements.
        dp[0] = 1; 
        
        // Iterate through each number in the array
        for (int num : arr) {
            // Traverse backwards to avoid using the same number multiple times
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
};