class Solution {
private:

    // Tabulation Solution
    int solveTab(vector<int>& val, int n){

        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                int ans = INT_MAX;
                for(int k = i+1; k < j; k++){
                    ans = min(ans, val[i]*val[j]*val[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solveTab(values, n);
    }
};