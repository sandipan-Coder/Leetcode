class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int n = dimensions.size();
        long long maxDiagSq = -1;   // squared diagonal
        int maxArea = -1;

        for (int i = 0; i < n; i++) {

            int len = dimensions[i][0];
            int wid = dimensions[i][1];
            long long diagSq = 1LL * len * len + 1LL * wid * wid;
            int area = len * wid;

            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagSq)
                maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};