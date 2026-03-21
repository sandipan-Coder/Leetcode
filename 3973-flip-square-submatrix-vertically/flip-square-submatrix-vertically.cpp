class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        int eRow = x + k - 1;
        int eCol = y + k - 1;

        while(x < eRow) {
            for(int j = y; j <= eCol; j++)
                swap(grid[x][j], grid[eRow][j]);
            
            x++;
            eRow--;
        }

        return grid;
    }
};