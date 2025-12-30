class Solution {
private:

    bool isMagic(int rStart, int rEnd, int cStart, int cEnd, vector<vector<int>>& grid){
        
        bool seen[10] = {false};

        // Check distinct values 1–9
        for(int i = rStart; i <= rEnd; i++){
            for(int j = cStart; j <= cEnd; j++){
                int val = grid[i][j];
                if(val < 1 || val > 9 || seen[val])
                    return false;
                seen[val] = true;
            }
        }

        int sum = 0;
        int dia1 = 0;

        // Sum of 2 diagonal
        for(int i = rStart; i <= rEnd; i++){

            sum += grid[i][cStart + (i - rStart)];
            dia1 += grid[i][cEnd - (i - rStart)];
        }

        if(sum != dia1)
            return false;
        
        // Row sums
        for(int i = rStart; i <= rEnd; i++){
            int rowSum = 0;
            for(int j = cStart; j <= cEnd; j++)
                rowSum += grid[i][j];
            
            if(rowSum != sum)
                return false;
        }

        // Col Sums
        for(int j = cStart; j <= cEnd; j++){
            int colSum = 0;
            for(int i = rStart; i <= rEnd; i++)
                colSum += grid[i][j];
            
            if(colSum != sum)
                return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        if(row < 3 || col < 3)
            return 0;

        for(int i = 0; i <= (row - 3); i++){
            for(int j = 0; j <= (col - 3); j++){

                if(isMagic(i, i+2, j, j+2, grid))
                    count++;
            }
        }

        return count;
    }
};