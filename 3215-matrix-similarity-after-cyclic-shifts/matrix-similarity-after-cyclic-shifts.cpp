class Solution {
private:

    void left_shift(vector<int> &arr){

        reverse(arr.begin() + 1, arr.end());
        reverse(arr.begin(), arr.end());

        return;
    }

    void right_shift(vector<int> &arr){

        reverse(arr.begin(), arr.end());
        reverse(arr.begin() + 1, arr.end());

        return;
    }

public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> grid = mat;
        int count = k;

        count = (count % m);
        if(count == 0)
            return true;
        
        while(count){

            for(int i = 0; i < n; i++) {

                if(i % 2) 
                    right_shift(grid[i]);
                else
                    left_shift(grid[i]);
            }

            count--;
        }

        return (grid == mat);
    }
};