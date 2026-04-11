class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) 
            mp[nums[i]].push_back(i);
        
        for(auto it: mp) {
            if(it.second.size() >= 3) {
                int m = it.second.size();

                for(int i = 2; i < m; i++) {
                    int diff = it.second[i] - it.second[i - 2];
                    diff = 2 * diff;

                    ans = min(ans, diff);
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};