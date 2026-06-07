class Solution {
public:
    int search(string &pat, string &txt) {
        vector<int> target(26, 0);
        int len = pat.size();
        for (int i = 0; i < len; i++) {
            target[pat[i] - 'a']++;
        }
        
        vector<pair<int, int>> search(26, {0, 0});
        int sz = txt.size();
        int l = 0, r = 0;
        int cnt = 0;
        
        while (r < sz) {
            if (target[txt[r] - 'a'] == 0) {
                while (l < r) {
                    search[txt[l] - 'a'].first--;
                    l++;
                }
                r++;
                l = r;
                continue;
            }
            
            search[txt[r] - 'a'].first++;
            search[txt[r] - 'a'].second = r;
            
            while (search[txt[r] - 'a'].first > target[txt[r] - 'a']) {
                search[txt[l] - 'a'].first--;
                l++;
            }
            
            int curr_len = r - l + 1;
            if (curr_len == len) cnt++;
            
            r++;
        }
        return cnt;
    }
};