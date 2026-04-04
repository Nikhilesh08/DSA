class Solution {
public:
    void diagonal(int temp, string &ans, vector<vector<char>>& mat) {
        int row = 0;
        int m = mat.size();
        int n = mat[0].size();
        while (row < m && temp < n) {
            ans += mat[row][temp];
            row++;
            temp++;
        }
    }
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        vector<vector<char>> mat(rows, vector<char>(cols, ' ')); 
        int ptr = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[ptr];
                ptr++;
            }
        }
        string ans = "";
        for (int temp = 0; temp < cols; temp++) {
            diagonal(temp, ans, mat);
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};