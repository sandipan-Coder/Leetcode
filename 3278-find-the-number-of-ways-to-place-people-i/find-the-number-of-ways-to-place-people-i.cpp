class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){

            if(a[0] == b[0])
                return a[1] > b[1];
            
            return a[0] < b[0];
        });

        for(int i = 0; i < n; i++){
            int cx = points[i][0];
            int cy = points[i][1];
            int mark = INT_MIN;

            for(int j = i+1; j < n; j++){
                int tx = points[j][0];
                int ty = points[j][1];

                if(ty > cy)
                    continue;
                if(ty > mark){
                    ans++;
                    mark = ty;
                }
            }
        }

        return ans;
    }
};