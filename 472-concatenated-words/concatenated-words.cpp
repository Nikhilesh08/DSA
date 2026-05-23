class Solution {
public:
    unordered_set<string> st;       
    bool solve(int idx, const string& s, vector<int>& dp) {
        int n = s.size();
        if (idx == n) return true;
        if (dp[idx] != -1) return dp[idx];

        for (int l = 1; l <= n - idx; l++) {
            if (idx == 0 && l == n) continue; 
            
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(idx + l, s, dp)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0; 
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        for (const string& word : words) { 
            st.insert(word); 
        } 
        vector<string> ans;
        for(int i = 0; i < n; i++){
            vector<int> dp(words[i].size() + 1, -1);
            if(solve(0, words[i], dp)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};