class Solution {

    int MOD = 1e9 + 7;
    int dp[201][201][2];

private:

    // Recursion
    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {

        if(onesLeft == 0 && zerosLeft == 0)
            return 1;
        
        int result = 0;

        if(lastWasOne) { // Explore 0s

            for(int len = 1; len <= min(zerosLeft, limit); len++)
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % MOD;
        }
        else {  // Explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++)
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % MOD;
        }

        return result;
    }

    // Recursion + Memoization
    int solveMem(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {

        if(onesLeft == 0 && zerosLeft == 0)
            return 1;
        
        if(dp[onesLeft][zerosLeft][lastWasOne] != -1)
            return dp[onesLeft][zerosLeft][lastWasOne];

        int result = 0;

        if(lastWasOne) { // Explore 0s

            for(int len = 1; len <= min(zerosLeft, limit); len++)
                result = (result + solveMem(onesLeft, zerosLeft - len, false, limit)) % MOD;
        }
        else {  // Explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++)
                result = (result + solveMem(onesLeft - len, zerosLeft, true, limit)) % MOD;
        }

        return dp[onesLeft][zerosLeft][lastWasOne] = result;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        memset(dp, -1, sizeof(dp));

        // Recursive Solution
        /*
        int startsWithZero = solve(one, zero, true, limit);
        int startsWithOne = solve(one, zero, false, limit);
        */

        // Recursive + Memoization Solution
        int startsWithZero = solveMem(one, zero, true, limit);
        int startsWithOne = solveMem(one, zero, false, limit);

        return (startsWithZero + startsWithOne) % MOD;
    }
};