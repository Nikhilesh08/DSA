class Solution {
public:
    int minToggle(std::vector<int>& arr) {
        int n = arr.size();
        int total_ones = 0;
        
        for (int num : arr) {
            if (num == 1) {
                total_ones++;
            }
        }
        
        int min_toggles = n; 
        int ones_left = 0;
        
        for (int i = 0; i <= n; ++i) {
            int right_length = n - i;
            int ones_right = total_ones - ones_left;
            int zeros_right = right_length - ones_right;
            
            int current_toggles = ones_left + zeros_right;
            
            min_toggles = std::min(min_toggles, current_toggles);
            
            if (i < n && arr[i] == 1) {
                ones_left++;
            }
        }
        
        return min_toggles;
    }
};