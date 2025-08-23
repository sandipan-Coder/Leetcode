class Solution {
private:

    int minimumArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        int minRow = n;
        int maxRow = -1;
        int minCol = m;
        int maxCol = -1;

        for(int i = startRow; i < endRow; i++){
            for(int j = startCol; j < endCol; j++){

                if(grid[i][j]){
                    
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int calculateResult(vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;

        for(int rowSplit = 1; rowSplit < n; rowSplit++){
            for(int colSplit = 1; colSplit < m; colSplit++){

                // Case:- 1
                int top = minimumArea(0, rowSplit, 0, m, grid);
                int bottomLeft = minimumArea(rowSplit, n, 0, colSplit, grid);
                int bottomRight = minimumArea(rowSplit, n, colSplit, m, grid);

                ans = min(ans, top + bottomLeft + bottomRight);

                // Case:- 2
                int topLeft = minimumArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minimumArea(0, rowSplit, colSplit, m, grid);
                int bottom = minimumArea(rowSplit, n, 0, m, grid);

                ans = min(ans, topLeft + topRight + bottom);
            }
        }

        // Case:- 3
        for(int split1 = 1; split1 < n; split1++){
            for(int split2 = split1 + 1; split2 < n; split2++){

                int top = minimumArea(0, split1, 0, m, grid);
                int middle = minimumArea(split1, split2, 0, m, grid);
                int bottom = minimumArea(split2, n, 0, m, grid);

                ans = min(ans, top + middle + bottom);
            }
        }

        return ans;

    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rotateGrid(m, vector<int>(n, 0));

        int result = calculateResult(grid);

        // Rotate the initial Grid (Clock-wise).
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                rotateGrid[j][n-i-1] = grid[i][j];
            }
        }

        result = min(result, calculateResult(rotateGrid));

        return result;
    }
};