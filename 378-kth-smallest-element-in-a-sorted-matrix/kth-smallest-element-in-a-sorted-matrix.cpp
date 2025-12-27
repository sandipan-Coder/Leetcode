class Solution {
    int n;
private:

    int countSmallest(vector<vector<int>>& matrix, int x){

        int count = 0;
        int row = 0;
        int col = n - 1;

        while(row < n && col >= 0){

            if(matrix[row][col] <= x){
                count += (col + 1);
                row++;
            }
            else
                col--;
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int ans = 0;
        
        while(low <= high){

            int mid = low + (high - low) / 2;

            int smallCount = countSmallest(matrix, mid);
            if(smallCount < k)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};