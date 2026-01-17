class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        int maxSide = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {

                int topRight_x = min(topRight[i][0], topRight[j][0]);
                int bottomLeft_x = max(bottomLeft[i][0], bottomLeft[j][0]);

                int width = (topRight_x - bottomLeft_x);

                int topRight_y = min(topRight[i][1], topRight[j][1]);
                int bottomLeft_y = max(bottomLeft[i][1], bottomLeft[j][1]);

                int length = (topRight_y - bottomLeft_y);

                int side = min(width, length);
                maxSide = max(maxSide, side);
            }
        }

        return (1LL * maxSide * maxSide);
    }
};