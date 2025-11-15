class Solution {
    int dp[102][102];
private:

    // Recursive
    int solve(int i, int j, vector<int>& cuts){

        if(i > j)
            return 0;
        
        int mini = INT_MAX;

        for(int idx = i; idx <= j; idx++){

            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, idx - 1, cuts) +
                        solve(idx + 1, j, cuts);
                    
            mini = min(mini, cost);
        }

        return mini;
    }

    // Recursive + Memoization
    int solveMem(int i, int j, vector<int>& cuts){

        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for(int idx = i; idx <= j; idx++){

            int cost = cuts[j + 1] - cuts[i - 1] + solveMem(i, idx - 1, cuts) +
                        solveMem(idx + 1, j, cuts);
                    
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    // Bottom up
    int solveBottom(int n, vector<int>& cuts){

        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= n; j++){
                
                if(i > j)
                    continue;

                int mini = INT_MAX;
                for(int idx = i; idx <= j; idx++){

                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][idx - 1] +
                                dp[idx + 1][j];
                            
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        

        return dp[1][n];
    }

public:
    int minCost(int n, vector<int>& cuts) {

        int len = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        // Recursive
        // return solve(1, len, cuts);

        // Recursive + Memoization
        /*
        memset(dp, -1, sizeof(dp));
        return solveMem(1, len, cuts);
        */

        // Bottom up
        memset(dp, 0, sizeof(dp));
        return solveBottom(len, cuts);
    }
};