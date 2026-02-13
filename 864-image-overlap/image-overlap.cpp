class Solution {
    int n;
private:

    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {

        int count = 0;

        // Now travers grid A a try to find the overlap cells of grid B.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // Calculate index of B from index of A.

                /*
                    A[i][j] = B[i + rowOff][j + colOff]
                */

                int B_i = i + rowOff;
                int B_j = j + colOff;

                if(B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;
                
                if(A[i][j] == 1 && B[B_i][B_j] == 1)
                    count++;
            }
        }

        return count;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        n = img1.size();
        int maxOverlaps = 0;

        for(int rowOffSet = -n+1; rowOffSet < n; rowOffSet++) {
            for(int colOffSet = -n+1; colOffSet < n; colOffSet++) {

                int count = countOverlaps(img1, img2, rowOffSet, colOffSet);

                maxOverlaps = max(maxOverlaps, count);
            }
        }

        return maxOverlaps;
    }
};