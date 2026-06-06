#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    using ll = long long;
    string s;
    int n;
    
    ll dpTotNum[20][11][11];
    ll dpTotWav[20][11][11];

    pair<ll, ll> solve(int idx, int prev2, int prev, bool tight, bool lz) {
        if (idx == n) return {1, 0};
        
        if (!tight && !lz && dpTotNum[idx][prev2][prev] != -1) {
            return {dpTotNum[idx][prev2][prev], dpTotWav[idx][prev2][prev]};
        }

        ll totNum = 0;
        ll totScore = 0;
        int ub = tight ? (s[idx] - '0') : 9;

        for (int dig = 0; dig <= ub; dig++) {
            bool nxtLz = (lz && dig == 0);
            int nxtPrev2 = prev;
            int nxtPrev = nxtLz ? 10 : dig;
            bool nxtTight = (tight && dig == ub);

            auto [remTotNum, remTotScore] = solve(idx + 1, nxtPrev2, nxtPrev, nxtTight, nxtLz);

            ll currentScore = 0;
            if (!nxtLz && prev2 != 10 && prev != 10) {
                bool isPeak = (prev2 < prev && prev > dig);
                bool isValley = (prev2 > prev && prev < dig);
                if (isPeak || isValley) {
                    currentScore = 1;
                }
            }

            totNum += remTotNum;
            totScore += remTotScore + (currentScore * remTotNum);
        }

        if (!tight && !lz) {
            dpTotNum[idx][prev2][prev] = totNum;
            dpTotWav[idx][prev2][prev] = totScore;
        }
        
        return {totNum, totScore};
    }

    ll func(long long num) {
        if (num < 100) return 0;

        s = to_string(num);
        n = s.length();
        
        memset(dpTotNum, -1, sizeof(dpTotNum));
        memset(dpTotWav, -1, sizeof(dpTotWav));
        
        auto [totNum, totScore] = solve(0, 10, 10, true, true);
        return totScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
    }
};