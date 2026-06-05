class Solution {
public:
    bool isPower2(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }

    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();
        
        if (isPower2(n)) {
            k = k / 2;
        } else {
            k = k * 2;
        }
        
        if (k >= n) return "-1";
        
        string ans = "";
        
        for (char ch : s) {
            while (!ans.empty() && k > 0 && ans.back() > ch) {
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }
        
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        
        if (ans.empty()) return "-1";
        
        return ans;
    }
};