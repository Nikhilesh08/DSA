#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Edge Case 1: If the array has only 1 element, return it.
        if (n == 1) return arr[0];

        long long MOD = 1e9 + 7;
        int count_neg = 0;
        int count_zero = 0;
        int max_neg = -1e9; // Initialize to a very small number

        // First pass: Count zeroes, negatives, and find the max negative number
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) count_zero++;
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            }
        }

        // Edge Case 2: All elements are zeroes
        if (count_zero == n) return 0;
        
        // Edge Case 3: All zeroes and exactly one negative number
        if (count_neg == 1 && count_zero + count_neg == n) return 0;

        long long prod = 1;
        bool skipped = false;

        // Second pass: Calculate the product
        for (int i = 0; i < n; i++) {
            // Skip zeroes
            if (arr[i] == 0) continue;

            // If there's an odd number of negatives, skip the max negative (only once)
            if (count_neg % 2 != 0 && arr[i] == max_neg && !skipped) {
                skipped = true;
                continue;
            }

            // Multiply the absolute values safely using modulo
            prod = (prod * abs(arr[i])) % MOD;
        }

        return prod;
    }
};