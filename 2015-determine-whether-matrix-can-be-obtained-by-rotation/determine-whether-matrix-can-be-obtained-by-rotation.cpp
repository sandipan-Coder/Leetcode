class Solution {
private:

    void rotate_90_degree(vector<vector<int>>& mat) {

        int n = mat.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++) 
                swap(mat[i][j], mat[j][i]);
        }

        for(int i = 0; i < n; i++)
            reverse(mat[i].begin(), mat[i].end());

        return;
    }

    bool checker(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n = mat.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] != target[i][j])
                    return false;
            }
        }

        return true;
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        

        bool ans = checker(mat, target);
        if(ans == true)
            return true;
        
        int rotation_count = 0;

        while(rotation_count < 3) {

            rotate_90_degree(mat);
            bool ans = checker(mat, target);
            if(ans == true)
                return true;

            rotation_count++;
        }

        return false;
    }
};