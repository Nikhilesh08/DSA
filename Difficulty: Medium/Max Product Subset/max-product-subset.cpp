#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        long long MOD = 1e9 + 7;
        int count_neg = 0;
        int count_zero = 0;
        int max_neg = -1e9; 
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) count_zero++;
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            }
        }

        if (count_zero == n) return 0;
        if (count_neg == 1 && count_zero + count_neg == n) return 0;

        long long prod = 1;
        bool skipped = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            if (count_neg % 2 != 0 && arr[i] == max_neg && !skipped) {
                skipped = true;
                continue;
            }
            prod = (prod * abs(arr[i])) % MOD;
            if (prod < 0) {
                prod = (prod + MOD) % MOD; 
            }
        }

        return prod;
    }
};