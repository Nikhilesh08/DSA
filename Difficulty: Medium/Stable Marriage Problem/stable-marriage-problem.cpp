class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> woman_partner(n, -1);
        vector<bool> man_free(n, true);
        int free_count = n;
        
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int r = 0; r < n; r++) {
                rank[w][women[w][r]] = r;
            }
        }
        
        vector<int> next_proposal(n, 0);
        
        while (free_count > 0) {
            int m;
            for (m = 0; m < n; m++) {
                if (man_free[m]) break;
            }
            
            int w = men[m][next_proposal[m]];
            next_proposal[m]++;
            
            if (woman_partner[w] == -1) {
                woman_partner[w] = m;
                man_free[m] = false;
                free_count--;
            } else {
                int current_partner = woman_partner[w];
                
                if (rank[w][m] < rank[w][current_partner]) {
                    woman_partner[w] = m;
                    man_free[m] = false;
                    man_free[current_partner] = true;
                }
            }
        }
        
        vector<int> result(n);
        for (int w = 0; w < n; w++) {
            result[woman_partner[w]] = w;
        }
        
        return result;
    }
};