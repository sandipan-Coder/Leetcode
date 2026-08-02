class Solution {
private:

    int dp[502][502];

    bool approach1(vector<int>& piles){

        int n = piles.size();
        int total_stone = accumulate(piles.begin(), piles.end(), 0);
        memset(dp, -1, sizeof(dp));

        int alice = solve(0, n-1, piles);
        int bob = total_stone - alice;

        return (alice > bob);
    }

    int solve(int i, int j, vector<int>& piles){

        if(i > j)
            return 0;
        
        if(i == j)
            return piles[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        

        int take_i = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int take_j = piles[j] + min(solve(i, j-2, piles), solve(i+1, j-1, piles));

        return dp[i][j] = max(take_i, take_j);
    }

public:
    bool stoneGame(vector<int>& piles) {
        
        // Aproach 1 -> (Recursion, DP, Memoization)
        /*
        return approach1(piles);
        */

        return true;
    }
};