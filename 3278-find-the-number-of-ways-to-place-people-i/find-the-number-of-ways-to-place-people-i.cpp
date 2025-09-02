class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int cx = points[i][0];
            int cy = points[i][1];
            for(int j = 0; j < n; j++){
                int tx = points[j][0];
                int ty = points[j][1];

                if(i == j || cx > tx || ty > cy)
                    continue;
                
                bool flag = true;
                for(int k = 0; k < n; k++){

                    if(k == i || k == j)
                        continue;
                    if(points[k][0] >= cx && points[k][0] <= tx && points[k][1] >= ty && points[k][1] <= cy ){
                        flag = false;
                        break;
                    }
                }

                if(flag)
                    ans++;
            }
        }

        return ans;
    }
};