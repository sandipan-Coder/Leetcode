class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        int MOD = 1e9 + 7;
        unordered_map<int, int> mp;
        long long ans = 0;

        for(auto &it: points)
            mp[it[1]]++;
        
        long long edgeSum = 0;

        for(auto &it: mp){

            long long edges = (it.second * 1LL * (it.second - 1)) / 2;

            ans = (ans + (edges * edgeSum) % MOD) % MOD;

            edgeSum += edges;
        }

        return (int)ans;
    }
};