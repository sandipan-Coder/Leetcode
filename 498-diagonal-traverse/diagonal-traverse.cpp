class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int>ans;
        int n = mat.size();
        int m = mat[0].size();
        int col = 0, row = 0;
        bool up = true;
        
        while(row < n and col < m){
            if(up){
                while(row > 0 and col < m-1){
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(mat[row][col]);
                if(col == m-1)
                    row++;
                else
                    col++;
            }else{
                while(row < n-1 and col > 0){
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(mat[row][col]);
                if(row == n-1)
                    col++;
                else
                    row++;
            }
            up = !up;
        }

        return ans;
    }
};