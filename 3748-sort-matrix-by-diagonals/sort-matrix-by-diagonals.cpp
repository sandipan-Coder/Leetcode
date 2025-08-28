class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        // middle diagonal + bottom-left triangle
        for(int i = 0; i < n; i++){
            int col = 0;
            int row = i;
            vector<int> arr;

            while(row < n){
                arr.push_back(grid[row][col]);
                row++;
                col++;
            }

            sort(begin(arr), end(arr));

            col = 0;
            row = i;
            for(int j = arr.size()-1; j >= 0; j--){
                ans[row][col] = arr[j];
                row++;
                col++;
            }
        }

        // top-right triangle
        for(int j = 1; j < n; j++){
            int row = 0;
            int col = j;
            vector<int> arr;

            while(col < n){
                arr.push_back(grid[row][col]);
                row++;
                col++;
            }

            sort(begin(arr), end(arr));

            col = j;
            row = 0;
            for(int i = 0; i < arr.size(); i++){
                ans[row][col] = arr[i];
                row++;
                col++;
            }
        }

        return ans;
    }
};