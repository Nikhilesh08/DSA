class Solution {
    // Custom struct to return both count of valid numbers and the sum of waviness
    struct Result {
        long long count;
        long long sum;
    };

    // Memoization table: idx(20) x tight(2) x started(2) x p1(11) x p2(11)
    // We use 10 as a "null" value for digits before the number has started
    Result memo[20][2][2][11][11];

    Result dp(const string& S, int idx, bool tight, bool started, int p1, int p2) {
        if (idx == S.length()) {
            return {1, 0}; 
        }

        if (memo[idx][tight][started][p1][p2].count != -1) {
            return memo[idx][tight][started][p1][p2];
        }

        int limit = tight ? (S[idx] - '0') : 9;
        long long total_count = 0;
        long long total_sum = 0;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = tight && (d == limit);

            if (!started) {
                if (d == 0) {
                    Result res = dp(S, idx + 1, next_tight, false, 10, 10);
                    total_count += res.count;
                    total_sum += res.sum;
                } else {
                    Result res = dp(S, idx + 1, next_tight, true, d, 10);
                    total_count += res.count;
                    total_sum += res.sum;
                }
            } else {
                int is_wave = 0;
                if (p2 != 10 && p1 != 10) {
                    if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) {
                        is_wave = 1;
                    }
                }

                Result res = dp(S, idx + 1, next_tight, true, d, p1);
                total_count += res.count;
                total_sum += res.sum + res.count * is_wave; 
            }
        }

        return memo[idx][tight][started][p1][p2] = {total_count, total_sum};
    }

    long long solve(long long N) {
        if (N < 100) return 0;
        string S = to_string(N);
        
        // Reset the memoization table for each solve call to prevent state leakage between test cases
        memset(memo, -1, sizeof(memo));
        
        return dp(S, 0, true, false, 10, 10).sum;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};