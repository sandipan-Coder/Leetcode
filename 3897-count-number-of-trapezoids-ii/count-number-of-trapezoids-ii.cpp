class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        int n = points.size();
        int inf = 1e9 + 7;
        int ans = 0;

        unordered_map<float, vector<float>> slopeToIntercept; // Slop -> {Intercept}
        unordered_map<int, vector<float>> midToSlope;        // Midpoints -> {Slops}

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {

                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                float slop, intercept;

                if (x2 == x1) {
                    slop = inf;
                    intercept = x1;
                } else {
                    slop = (float)dy / dx;
                    intercept = (float)(y1 * dx - x1 * dy) / dx;
                }

                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[slop].push_back(intercept);
                midToSlope[mid].push_back(slop);
            }
        }

        // This is same as problem -> I
        for (auto &it : slopeToIntercept) {
            if (it.second.size() == 1) 
                continue;
            
            // Destructure same intercept points with their frequencies
            map<float, int> mp;
            for (float intercepts : it.second) 
                mp[intercepts]++;
            
            int prevCount = 0;
            for (auto &it : mp) {

                int count = it.second;
                ans += (prevCount * count);
                prevCount += count;
            }
        }

        for (auto& [_, mts] : midToSlope) {
            if (mts.size() == 1) 
                continue;
            
            map<float, int> cnt;
            for (float slop : mts) 
                cnt[slop]++;
            
            int prevCount = 0;
            for (auto& [_, count] : cnt) {
                ans -= prevCount * count;
                prevCount += count;
            }
        }
        
        return ans;
    }
};