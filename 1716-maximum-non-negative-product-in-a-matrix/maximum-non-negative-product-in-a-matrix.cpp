class Solution {

    typedef long long ll;
    int n, m;
    int MOD = 1e9 + 7;
    vector<vector<pair<ll, ll>>> dp;
private:

    pair<ll, ll> solve(int row, int col, vector<vector<int>>& grid) {

        if(row == n-1 && col == m-1)
            return {grid[n-1][m-1], grid[n-1][m-1]};
        
        if(dp[row][col] != make_pair(LLONG_MIN, LLONG_MAX))
            return dp[row][col];
        
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        // Down
        if(row + 1 < n) {

            auto [downMax, downMin] = solve(row + 1, col, grid);
            maxVal = max({maxVal, grid[row][col] * downMax, grid[row][col] * downMin});
            minVal = min({minVal, grid[row][col] * downMax, grid[row][col] * downMin});
        }

        // Right
        if(col + 1 < m) {

            auto [rightMax, rightMin] = solve(row, col + 1, grid);
            maxVal = max({maxVal, grid[row][col] * rightMax, grid[row][col] * rightMin});
            minVal = min({minVal, grid[row][col] * rightMax, grid[row][col] * rightMin});
        }

        return dp[row][col] = {maxVal, minVal};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>(m, {LLONG_MIN, LLONG_MAX}));

        auto [maxPro, minPro] = solve(0, 0, grid);

        return (maxPro < 0) ? -1 : (maxPro % MOD);
    }
};