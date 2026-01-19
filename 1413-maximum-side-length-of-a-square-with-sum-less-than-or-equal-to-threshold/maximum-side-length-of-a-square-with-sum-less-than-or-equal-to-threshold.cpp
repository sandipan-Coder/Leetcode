class Solution {
    int rows;
    int cols;
private:

    //function for squreSum
    int squredSum(int i, int j, int r2, int c2, vector<vector<int>> &prefix) {

        int sum = prefix[r2][c2];

        if(i > 0)
            sum -= prefix[i-1][c2];

        if(j > 0)
            sum -= prefix[r2][j-1];
        
        if(i > 0 && j > 0)
            sum += prefix[i - 1][j - 1];

        return sum;
    }

    bool isPossible(int side, vector<vector<int>> &prefix, int &threshold) {

        for(int i = 0; i + side - 1 < rows; i++) {
            for(int j = 0; j + side - 1 < cols; j++) {
                
                int r2 = i + side - 1;
                int c2 = j + side - 1;

                if(squredSum(i, j, r2, c2, prefix) <= threshold) 
                    return true;
            }
        }

        return false;
    }

public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        rows = mat.size();
        cols = mat[0].size();
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

        
        

        // ********* Approach-1 (Using 2D Prefix Sum and finding best side square)
        //T.C : O(rows * cols * min(rows, cols))
        //S.C : O(rows * cols)


        // Check all sub-matrix
        /*
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                for(int k = best; k < min(rows-i, cols-j); k++) {
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = squredSum(i, j, r2, c2, prefix);

                    if(sum <= threshold)
                        best = max(best, k+1);
                    else
                        break;
                }
            }
        }
        */

        // ************ Approach-2 (Using 2D Prefix Sum and binarysearch the square side)
        //T.C : O(rows * cols * log(min(rows, cols)))
        //S.C : O(rows * cols)
        int low = 1;
        int high = min(rows, cols);

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(mid, prefix, threshold)) {
                best = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return best;
    }
};