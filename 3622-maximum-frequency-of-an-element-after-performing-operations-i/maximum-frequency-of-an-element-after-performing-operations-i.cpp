class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        unordered_map<int, int> mp;
        vector<pair<int, int>> line;

        for(int i = 0; i < nums.size(); i++){
           mp[nums[i]]++;
           line.push_back({nums[i] - k, 1});
           line.push_back({nums[i], 2});
           line.push_back({nums[i] + k, 3});
        }
        sort(line.begin(), line.end());
        int ans = 0;
        int cnt = 0;

        for(auto &[num,type]: line){
            if(type == 1) 
                cnt++;
            else if(type == 3) 
                cnt--;
            int requiredOperation = cnt - mp[num];

            ans = max(ans, mp[num] + min(requiredOperation, numOperations));
        }

        return ans;
    }
};