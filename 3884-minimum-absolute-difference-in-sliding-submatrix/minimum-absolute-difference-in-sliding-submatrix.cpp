class Solution {
private:

    int evaluate_minDiff(int &sRow, int &sCol, int &eRow, int &eCol, vector<vector<int>>& grid) {

        vector<int> elements;

        for(int i = sRow; i <= eRow; i++) {
            for(int j = sCol; j <= eCol; j++)
                elements.push_back(grid[i][j]);
        }

        sort(begin(elements), end(elements));
        int n = elements.size();
        int minDiff = INT_MAX;

        for(int i = 1; i < n; i++) {
            
            if(elements[i] == elements[i - 1])
                continue;
            
            int diff = abs(elements[i] - elements[i - 1]);
            minDiff = min(minDiff, diff);
        }

        return (minDiff == INT_MAX) ? 0 : minDiff;
    }

public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans((n - k + 1), vector<int>((m - k + 1), 0));
        if(k == 1)
            return ans;
        
        for(int i = 0; i <= (n - k); i++) {
            for(int j = 0; j <= (m - k); j++) {

                int eRow = (i + k - 1);
                int eCol = (j + k - 1);

                int res = evaluate_minDiff(i, j, eRow, eCol, grid);
                ans[i][j] = res;
            }
        }

        return ans;
    }
};