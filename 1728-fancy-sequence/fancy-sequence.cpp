class Fancy {
    vector<long long> nums;
    long long mul = 1;
    long long add = 0;
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {}
// val=(val*mul)+add
    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        nums.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= nums.size()) return -1;
        return (nums[idx] * mul + add) % MOD;
    }
};