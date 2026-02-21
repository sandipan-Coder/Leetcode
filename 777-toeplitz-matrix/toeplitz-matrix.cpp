class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        // Approach 1:- O(N) space and O(N * M) Time
        /*
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int idx = (i - j);
                int val = matrix[i][j];

                if((mp[idx].size() > 0) && (mp[idx].back() != val))
                    return false;
                
                mp[idx].push_back(val);
            }
        }
        */

        // Approach 2:- O(N * M) Time + O(1) space.
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                int curr = matrix[i][j];
                int prev = matrix[i - 1][j - 1];

                if(curr != prev)
                    return false;
            }
        }

        return true;
    }
};