class Solution {
    int n, m;
    int dp[1001][1001];
private:

    // Recursive
    int solve(int i, int j, string s1, string s2){

        if(i >= n && j >= m)
            return 0;
        
        if(i >= n)
            return s2[j] + solve(i, j + 1, s1, s2);
        if(j >= m)
            return s1[i] + solve(i + 1, j, s1, s2);
        
        if(s1[i] == s2[j])
            return solve(i + 1, j + 1, s1, s2);
        
        // Two Possibility
        int delete_s1_i = s1[i] + solve(i + 1, j, s1, s2);
        int delete_s2_j = s2[j] + solve(i, j + 1, s1, s2);

        return min(delete_s1_i, delete_s2_j);
    }

    // Recursive + Memoization
    int solveMem(int i, int j, string &s1, string &s2){

        if(i >= n && j >= m)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(i >= n)
            return dp[i][j] = s2[j] + solveMem(i, j + 1, s1, s2);
        else if(j >= m)
            return dp[i][j] = s1[i] + solveMem(i + 1, j, s1, s2);
        
        if(s1[i] == s2[j])
            return dp[i][j] = solveMem(i + 1, j + 1, s1, s2);
        
        // Two Possibility
        int delete_s1_i = s1[i] + solveMem(i + 1, j, s1, s2);
        int delete_s2_j = s2[j] + solveMem(i, j + 1, s1, s2);

        return dp[i][j] = min(delete_s1_i, delete_s2_j);
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        
        n = s1.length();
        m = s2.length();

        // Recursive
        // return solve(0, 0, s1, s2);

        // Recursive + Memoization
        memset(dp, -1, sizeof(dp));
        return solveMem(0, 0, s1, s2);
    }
};