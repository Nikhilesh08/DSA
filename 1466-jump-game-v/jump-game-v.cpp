#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int memo[1000];
    int n;

    int dfs(int i, vector<int>& arr, int d) {
        if (memo[i] != -1) return memo[i];
        
        int res = 1; // Current index is always visited
        
        // Jump right
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; ++j) {
            res = max(res, 1 + dfs(j, arr, d));
        }
        
        // Jump left
        for (int j = i - 1; j >= max(i - d, 0) && arr[j] < arr[i]; --j) {
            res = max(res, 1 + dfs(j, arr, d));
        }
        
        return memo[i] = res;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        fill(memo, memo + n, -1);
        int max_jumps = 0;
        
        for (int i = 0; i < n; ++i) {
            max_jumps = max(max_jumps, dfs(i, arr, d));
        }
        
        return max_jumps;
    }
};