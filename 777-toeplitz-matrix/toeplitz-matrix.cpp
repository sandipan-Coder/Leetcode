class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

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

        return true;
    }
};