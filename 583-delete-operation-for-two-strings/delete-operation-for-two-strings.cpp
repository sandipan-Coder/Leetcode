class Solution {
    int n, m;
    int dp[501][501];

private:

    int solve(int i, int j, string &word1, string &word2){

        if(i >= n && j >= m)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i >= n)
            return dp[i][j] = 1 + solve(i, j+1, word1, word2);
        else if(j >= m)
            return dp[i][j] = 1 + solve(i+1, j, word1, word2);
        
        if(word1[i] == word2[j])
            return dp[i][j] = solve(i+1, j+1, word1, word2);

        int delete_word1_i = 1 + solve(i+1, j, word1, word2);
        int delete_word2_j = 1 + solve(i, j+1, word1, word2);

        return dp[i][j] = min(delete_word1_i, delete_word2_j);
    }

public:
    int minDistance(string word1, string word2) {
        
        n = word1.size();
        m = word2.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, word1, word2);
    }
};