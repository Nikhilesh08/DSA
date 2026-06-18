class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> row_first(n, -1), row_last(n, -1);
        vector<int> col_first(m, -1), col_last(m, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    if (row_first[i] == -1) row_first[i] = j;
                    row_last[i] = j;
                    
                    if (col_first[j] == -1) col_first[j] = i;
                    col_last[j] = i;
                }
            }
        }
        
        int total_coverage = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    // left
                    if (row_first[i] != -1 && row_first[i] < j) total_coverage++;
                    //right
                    if (row_last[i] != -1 && row_last[i] > j) total_coverage++;
                    // up
                    if (col_first[j] != -1 && col_first[j] < i) total_coverage++;
                    // down
                    if (col_last[j] != -1 && col_last[j] > i) total_coverage++;
                }
            }
        }
        
        return total_coverage;
    }
};