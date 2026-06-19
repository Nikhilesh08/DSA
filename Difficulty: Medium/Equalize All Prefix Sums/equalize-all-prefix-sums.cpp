class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        
        // We use long long for sums to prevent any integer overflow
        long long left_sum = 0;  // Sum of elements <= median
        long long right_sum = 0; // Sum of elements >= median
        
        for (int i = 0; i < n; ++i) {
            int k = i / 2; // k is the index of our median
            
            if (i % 2 == 0) {
                // RULE B: Length is ODD (i is even). 
                // The median shifts forward.
                
                if (i == 0) {
                    left_sum += arr[0];
                } else {
                    // Move the old median from the Right Bucket to the Left Bucket
                    left_sum += arr[k];
                    
                    // Add the new number to the Right Bucket, and subtract the old median we just moved
                    right_sum += arr[i] - arr[k]; 
                }
                
                // Formula for odd length: Median - Left Sum + Right Sum
                ans[i] = arr[k] - left_sum + right_sum;
                
            } else {
                // RULE A: Length is EVEN (i is odd). 
                // The median stays exactly where it is.
                
                // The new number just drops straight into the Right Bucket
                right_sum += arr[i];
                
                // Formula for even length: Right Sum - Left Sum
                ans[i] = right_sum - left_sum;
            }
        }
        
        return ans;
    }
};