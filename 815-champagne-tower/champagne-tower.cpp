class Solution {
    double dp[101][101];
private:

    double helper(int &poured, int i, int j) {

        if(i < 0 || j < 0 || i < j) 
            return 0.0;
        
        if(i == 0 && j == 0) // At the top of the champagne glass
            return poured;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // One glass is full with the help of it's top left and right glass.
        double top_left = (helper(poured, i - 1, j - 1) - 1) / 2.0;
        if(top_left < 0)
            top_left = 0.0;
        
        double top_right = (helper(poured, i - 1, j) - 1) / 2.0;
        if(top_right < 0)
            top_right = 0.0;

        return dp[i][j] = (top_left + top_right);
    }

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        if(poured == 0)
            return 0.0;
        
        if((poured == 1) && (query_row == 0))
            return 1.0;
        if((poured == 1) && (query_row > 0))
            return 0.0;
        
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++)
                dp[i][j] = -1;
        }

        return min(1.0, helper(poured, query_row, query_glass));
    }
};