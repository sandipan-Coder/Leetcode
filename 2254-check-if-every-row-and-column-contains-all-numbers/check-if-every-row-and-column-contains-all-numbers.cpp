class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        
        int n = mat.size();

        for(int i = 0; i < n; i++){
            vector<int> rowArr(n+1, 0);
            vector<int> colArr(n+1, 0);
            for(int j = 0; j < n; j++){

                if(rowArr[mat[i][j]])
                    return false;
                if(colArr[mat[j][i]])
                    return false;
                
                rowArr[mat[i][j]]++;
                colArr[mat[j][i]]++;
            }
        }

        return true;
    }
};