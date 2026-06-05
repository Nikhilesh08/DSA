class Solution {
public:
    int maxSubstring(string s) {
        int max_sum = -1;
        int curr_sum = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int val = (s[i] == '0') ? 1 : -1;
            curr_sum += val;
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        
        return max_sum;
    }
};