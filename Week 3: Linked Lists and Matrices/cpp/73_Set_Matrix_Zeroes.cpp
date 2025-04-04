class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size(); // Number of rows
            int n = matrix[0].size(); // Number of columns

            bool firstRowZero = false, firstColZero = false;

            // Step 1: Determine if the first row or column shoulb be set to zero
            for (int i = 0; i < m; i++) {
                if (matrix[i][0] == 0) {
                    firstColZero = true;
                    break;
                }
            }
            for (int j = 0; j < n; j++) {
                if (matrix[0][j] == 0) {
                    firstRowZero = true;
                    break;
                }
            }
            // Step 2: Use first row and column as markers
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0; // Mark the first cell of the row
                        matrix[0][j] = 0; // Mark the first cell of the column
                    }
                }
            }
            // Step 3: Set elements to zero based on markers
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
            // Step 4: Handle the first row and column separately
            if (firstRowZero) {
                for (int j = 0; j < n; j++) {
                    matrix[0][j] = 0;
                }
            }
            if (firstColZero) {
                for (int i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
    };
