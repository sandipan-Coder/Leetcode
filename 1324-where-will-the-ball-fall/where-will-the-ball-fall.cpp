class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int> ans(m, -1);

        for(int ball = 0; ball < m; ball++) {

            int row = 0;
            int col = ball;
            bool flag = false;

            while(row < n && col < m) {

                // grid[row][col] == 1
                if(grid[row][col] == 1) {
                    
                    // If col is last then ball can't fall.
                    if(col == m-1){
                        flag = true;
                        break;
                    }
                    else if(grid[row][col + 1] == -1){  // if next column has value -1.
                        flag = true;
                        break;
                    } 
                        
                    col++;
                }
                else {
                    // If column is fast then ball can't fall.
                    if(col == 0){
                        flag = true;
                        break;
                    }
                    else if(grid[row][col - 1] == 1){   // if prev column has value 1.
                        flag = true;
                        break;
                    } 
                    
                    col--;
                }
                row++;
            }

            if(!flag)
                ans[ball] = col;
        }

        return ans;
    }
};