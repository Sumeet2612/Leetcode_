class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> res(cols, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < cols; j++) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
        
    }
};