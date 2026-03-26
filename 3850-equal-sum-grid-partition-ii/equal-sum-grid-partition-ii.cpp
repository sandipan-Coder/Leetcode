class Solution {

    typedef long long ll;
    ll totalSum = 0;

private:

    bool check_Horizontal_Cut(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();
        ll topSum = 0;
        unordered_set<ll> st;

        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m; j++) {

                topSum += arr[i][j];
                st.insert(arr[i][j]);
            }

            ll bottomSum = (totalSum - topSum);
            ll diff = (topSum - bottomSum);

            if(diff == 0)
                return true;
            if(diff == (ll)arr[0][0])  // If first element of first row is same as diff
                return true;
            if(diff == (ll)arr[0][m - 1])  // If last element of first row is same as diff
                return true;
            if(diff == (ll)arr[i][0])  // This is for single column array.
                return true;
            
            // If cutting index is more then 0 and no. of column greater than 1 then we can remove any element from the array.
            if(i > 0 && m > 1 && st.count(diff))
                return true;
        }

        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        // For vertical cut we check it using horizontal cut function just taking the transpose of the given matrix.
        vector<vector<int>> transposeMatrix(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){

                totalSum += grid[i][j];
                transposeMatrix[j][i] = grid[i][j];
            }
        }

        // Horizontal Cut checking.
        if(check_Horizontal_Cut(grid))
            return true;
        
        reverse(begin(grid), end(grid));  // This is for both side checking

        if(check_Horizontal_Cut(grid))
            return true;

        // Vertical cut checking
        if(check_Horizontal_Cut(transposeMatrix))
            return true;

        reverse(begin(transposeMatrix), end(transposeMatrix));  // This is for both side checking

        if(check_Horizontal_Cut(transposeMatrix))
            return true;

        return false;
    }
};