class Solution {
  public:
    int maxSubstring(string &s) {
        int current_sum = 0;
        int max_sum = -1; // Initializing to -1 automatically handles the "all 1s" edge case
        
        for (char c : s) {
            // Map '0' to +1 and '1' to -1
            int val = (c == '0') ? 1 : -1;
            
            current_sum += val;
            
            // Update the maximum difference found so far
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            
            // GREEDY CHOICE: If our current sum drops below 0, 
            // the current substring is dragging us down. 
            // It's better to abandon it and start a new substring from the next character.
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        
        return max_sum;
    }
};