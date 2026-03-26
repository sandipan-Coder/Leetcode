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
            if(diff == (ll)arr[0][0])
                return true;
            if(diff == (ll)arr[0][m - 1])
                return true;
            if(diff == (ll)arr[i][0])
                return true;
            
            if(i > 0 && m > 1 && st.count(diff))
                return true;
        }

        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> transposeMatrix(m, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){

                totalSum += grid[i][j];
                transposeMatrix[j][i] = grid[i][j];
            }
        }

        if(check_Horizontal_Cut(grid))
            return true;
        
        reverse(begin(grid), end(grid));

        if(check_Horizontal_Cut(grid))
            return true;

        if(check_Horizontal_Cut(transposeMatrix))
            return true;

        reverse(begin(transposeMatrix), end(transposeMatrix));

        if(check_Horizontal_Cut(transposeMatrix))
            return true;

        return false;
    }
};