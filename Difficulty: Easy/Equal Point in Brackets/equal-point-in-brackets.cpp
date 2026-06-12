class Solution {
  public:
    int findIndex(string &s) {
        int n = s.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') cnt++;
        }
        
        int open = 0, close = 0;
        
        for (int i = 0; i <= n; i++) {
            if (open == (cnt - close)) {
                return i;
            }
            
            if (i < n) {
                if (s[i] == '(') {
                    open++;
                } else if (s[i] == ')') {
                    close++;
                }
            }
        }
        
        return 0;
    }
};