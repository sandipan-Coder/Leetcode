class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = 0;
        int jumps = 0;

        while(high < n-1){

            int longest = 0;
            for(int idx = low; idx <= high; idx++)
                longest = max(longest, idx + nums[idx]);

            if(longest <= high)
                return -1;
            low = high + 1;
            high = longest;
            jumps++;
        }

        return jumps;
    }
};