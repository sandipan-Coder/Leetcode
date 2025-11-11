class Solution {

    int len;
    // m -> 0's && n -> 1'
    int dp[601][101][101];
private:

    vector<int> countZeroAndOnes(string &str){

        int zeros = 0;
        int ones = 0;

        for(int i = 0; i < str.length(); i++){
            if(str[i] == '0')
                zeros++;
            else
                ones++;
        }

        return {zeros, ones};
    }

    int solve(int idx, vector<string>& strs, int m, int n){

        if(idx >= len)
            return 0;
        if(m < 0 || n < 0)
            return -1e8;
        
        if(dp[idx][m][n] != -1)
            return dp[idx][m][n];
        
        vector<int> count = countZeroAndOnes(strs[idx]);
        int take = 0;
        
        int notTake = solve(idx + 1, strs, m, n);
        if(m >= count[0] && n >= count[1])
            take = 1 + solve(idx + 1, strs, m-count[0], n-count[1]);

        return dp[idx][m][n] = max(take, notTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        len = strs.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, strs, m, n);
    }
};