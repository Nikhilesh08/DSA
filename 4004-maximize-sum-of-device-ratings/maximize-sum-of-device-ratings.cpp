class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        if (n == 1) {
            long long base_sum = 0;
            for(int i = 0; i < m; i++) {
                base_sum += units[i][0];
            }
            return base_sum;
        }
        long long min2_sum = 0;
        int global_min = INT_MAX;
        int smallest_min2 = INT_MAX;
        for (int i = 0; i < m; i++) {
            int mini1 = INT_MAX, mini2 = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (units[i][j] < mini1) {
                    mini2 = mini1;
                    mini1 = units[i][j];
                } else if (units[i][j] < mini2) {
                    mini2 = units[i][j];
                }
            }
            if (mini1 < global_min) {
                global_min = mini1;
            }
            if (mini2 < smallest_min2) {
                smallest_min2 = mini2;
            }
            min2_sum += mini2;
        }
        return (long long)global_min + min2_sum - smallest_min2;
    }
};