class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        for (int i = num1; i <= num2; ++i) {
            string s = to_string(i);
            int n = s.length();
            if (n < 3) continue;
            for (int j = 1; j < n - 1; ++j) {
                int prev = s[j-1] - '0';
                int curr = s[j] - '0';
                int next = s[j+1] - '0';
                if ((curr > prev && curr > next) || (curr < prev && curr < next)) {
                    total_waviness++;
                }
            }
        }
        return total_waviness;
    }
};