class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int MOD = 1e9 + 7;
        int xorVal = 0;

        for(auto it: queries) {

            int idx = it[0];
            int end = it[1];
            int skip = it[2];
            int val = it[3];

            while(idx <= end) {
                nums[idx] = (1LL * nums[idx] * val) % MOD;
                idx += skip;
            }
        }

        for(auto num: nums)
            xorVal ^= num;

        return xorVal;
    }
};