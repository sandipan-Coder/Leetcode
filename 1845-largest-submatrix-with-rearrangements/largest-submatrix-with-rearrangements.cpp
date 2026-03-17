class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;

        for(int j = 0; j < m; j++) {
            for(int i = 1; i < n; i++) {

                if(matrix[i][j] == 0) 
                    continue;
                else
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        for(int i = 0; i < n; i++)
            sort(matrix[i].begin(), matrix[i].end(), greater<>());
        
        for(int i = 0; i < n; i++) {
            int height = INT_MAX;
            for(int j = 0; j < m; j++) {
                
                height = min(height, matrix[i][j]);
                int Area = (height * (j + 1));
                area = max(area, Area);
            }
        }

        return area;
    }
};