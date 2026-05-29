class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;
        for (int num : nums) {
            int currentSum = 0;
            while (num > 0) {
                currentSum += num % 10;
                num /= 10;
            }
            minSum = min(minSum, currentSum);
        }
        return minSum;
    }
};