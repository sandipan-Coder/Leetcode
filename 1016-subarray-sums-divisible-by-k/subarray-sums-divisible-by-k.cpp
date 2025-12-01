class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int subCount = 0;
        int preSum = 0;
        mp[0] = 1;

        for(int &num: nums){

            preSum = (preSum + num) % k;
            if(preSum < 0)
                preSum += k;

            if(mp.count(preSum))
                subCount += mp[preSum];
            
            mp[preSum]++;
        }

        return subCount;
    }
};