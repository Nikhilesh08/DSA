class Solution {
public:
    unordered_set<string> st;
    vector<int> dp; 
    int n;         
    bool solve(int idx, const string& s) {
        if (idx == n) return true;
        if (dp[idx] != -1) return dp[idx];
        for (int l = 1; l <= n - idx; l++) {
            if (st.find(s.substr(idx, l)) != st.end() && solve(idx + l, s)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        dp.assign(n + 1, -1);
        for (const string& word : wordDict) { 
            st.insert(word); 
        } 
        return solve(0, s);
    }
};