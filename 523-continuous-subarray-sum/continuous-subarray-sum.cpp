class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp; // Remainder -> Index
        int sum = 0;

        mp[0] = -1;

        for(int i = 0; i < n; i++) {

            sum += nums[i];
            int remainder = (sum % k);

            // Check if the remainder is present in map or not.
            if(mp.count(remainder)) {
                if((i - mp[remainder]) >= 2)
                    return true;
            } else {
                mp[remainder] = i;
            }
        }

        return false;
    }
};