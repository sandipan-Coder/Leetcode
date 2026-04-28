class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] % x != grid[0][0] % x)
                    return -1;
                
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());
        int ans = 0;
        int midValue = floor((arr.size()) / 2);
        int value = arr[midValue];

        for(int i = 0; i < arr.size(); i++){

            int res = abs(value - arr[i]);
            ans += res / x;
        }

        return ans;
    }
};