class Solution {
private:
    // Recursive
    int pathSumHelper(vector<vector<int>>& triangle, int idx, int row){

        if(row == triangle.size() - 1)
            return triangle[row][idx];

        int down = pathSumHelper(triangle, idx , row + 1);
        int diagonal = pathSumHelper(triangle, idx + 1, row + 1);

        return triangle[row][idx] + min(down, diagonal);
    }

    // Top-Down
    int pathSumHelperDP(vector<vector<int>>& triangle, int idx, int row, vector<vector<int>> &dp){

        if(row == triangle.size() - 1)
            return triangle[row][idx];

        if(dp[row][idx] != INT_MAX)
            return dp[row][idx];

        int down = pathSumHelperDP(triangle, idx , row + 1, dp);
        int diagonal = pathSumHelperDP(triangle, idx + 1, row + 1, dp);

        return dp[row][idx] = triangle[row][idx] + min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Recursive
        /*
        return pathSumHelper(triangle, 0, 0);
        */

        // Top-Down
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return pathSumHelperDP(triangle, 0, 0, dp);

    }
};