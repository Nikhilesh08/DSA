class Solution {
public:
    int n;
    bool isUnique(const string& s) {
        vector<int> hash(26, 0);
        for (char c : s) {
            hash[c - 'a']++;
            if (hash[c - 'a'] > 1) return false;
        }
        return true;
    }
    int solve(int idx, string ans, vector<string>& arr) {
        if(idx == n){
            return ans.size();
        }
        int not_pick = solve(idx + 1, ans, arr);
        int pick = 0;
        string curr = arr[idx];
        if (isUnique(ans + curr)) {
            pick = solve(idx + 1, ans + curr, arr);
        }
        return max(pick, not_pick);
    }

    int maxLength(vector<string>& arr) {
        n = arr.size();
        return solve(0, "", arr);
    }
};