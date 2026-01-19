class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        int best = 0; // Store best squre side which sum is equal to threshold

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));

        // prefix[i][j] = sum of matrix from top_left (0, 0) -> (i, j);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0)
                            + (j > 0 ? prefix[i][j - 1] : 0)
                            - ((i > 0 && j > 0) ? prefix[i -1][j - 1] : 0) 
                            + mat[i][j];
            }
        }

        
        // Lemda function for squreSum
        auto squredSum = [&](int i, int j, int r2, int c2) {

            int sum = prefix[r2][c2];

            if(i > 0)
                sum -= prefix[i-1][c2];

            if(j > 0)
                sum -= prefix[r2][j-1];
            
            if(i > 0 && j > 0)
                sum += prefix[i - 1][j - 1];

            return sum;
        };

        // Check all sub-matrix
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                for(int k = best; k < min(rows-i, cols-j); k++) {
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = squredSum(i, j, r2, c2);

                    if(sum <= threshold)
                        best = max(best, k+1);
                    else
                        break;
                }
            }
        }

        return best;
    }
};