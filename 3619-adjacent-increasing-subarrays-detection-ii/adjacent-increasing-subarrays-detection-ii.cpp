class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int inc = 1;
        int prevInc = 0;
        int maxLen = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++){

            if(nums[i] > nums[i - 1])
                inc++;
            else{
                maxLen = max(maxLen, max(inc >> 1, min(inc, prevInc)));

                prevInc = inc;
                inc = 1;
            }
        }

        maxLen = max(maxLen, max(inc >> 1, min(inc, prevInc)));

        return maxLen;
    }
};