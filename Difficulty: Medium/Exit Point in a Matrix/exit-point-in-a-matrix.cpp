class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {0, 0}; 

        int i = 0, j = 0;
        int n = mat.size(), m = mat[0].size();
        int dir = 0; 

        while (true) {
            if (mat[i][j] == 1) {
                mat[i][j] = 0;
                dir = (dir + 1) % 4; 
            }

            if (dir == 0) {
                if (j + 1 >= m) return {i, j};
                j++;
            } 
            else if (dir == 1) {
                if (i + 1 >= n) return {i, j};
                i++;
            } 
            else if (dir == 2) {
                if (j - 1 < 0) return {i, j};
                j--;
            } 
            else if (dir == 3) {
                if (i - 1 < 0) return {i, j};
                i--;
            }
        }
        
        return {0, 0}; 
    }
};