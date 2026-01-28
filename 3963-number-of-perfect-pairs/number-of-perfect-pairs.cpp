class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        
        int n = nums.size();
        long long ans = 0;
        int idx = 0;

        for(int &ele: nums)
            ele = abs(ele);
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){

            while(idx < n && (nums[idx] <= 2*nums[i]))
                idx++;
            
            ans += (idx - 1 - i);
        }

        return ans;
    }
};