class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int x: nums)
            mp[x]++;
        
        for(int i = 1; i <= n; i++) {
            int mul = k * i;

            if(mp.count(mul) == 0)
                return mul;
        }

        return (k * (n + 1));
    }
};