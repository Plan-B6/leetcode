class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int offset = 0;
        while (offset < n / 2) {
            for (int i = 0 + offset; i < n - 1 - offset; ++i) {
                swap(matrix[0 + offset][i], matrix[i][n - 1 - offset]);
                swap(matrix[0 + offset][i], matrix[n - 1 - i][0 + offset]);
                swap(matrix[n - 1 - offset][n - 1 - i], matrix[n - 1 - i][0 + offset]);
            }
            offset++;
        }
    }
};
