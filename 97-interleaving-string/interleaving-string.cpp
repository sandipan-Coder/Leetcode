class Solution {
    int n, m, N;
    int dp[201][101][101];
private:

    bool solve(int i, int j, int k, string &s1, string &s2, string &s3){

        if(i >= N && j >= n && k >= m)
            return true;
        if(i >= N)
            return false;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        bool ans = false;

        if(s1[j] == s3[i])
            ans = solve(i+1, j+1, k, s1, s2, s3);
        
        if(ans)
            return dp[i][j][k] = ans;
        
        if(s2[k] == s3[i])
            ans = solve(i+1, j, k+1, s1, s2, s3);
        
        if(s1[j] != s3[i] && s2[k] != s3[i])
            return dp[i][j][k] = false;
        
        return dp[i][j][k] =  ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        
        n = s1.length();
        m = s2.length();
        N = s3.length();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, s1, s2, s3);
    }
};