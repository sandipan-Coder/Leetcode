class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        int incr = 1, prevI = 0, maxLen = 0;

        for(int i = 1; i < n; i++){

            if(nums[i] > nums[i - 1])
                incr++;
            else{

                prevI = incr;
                incr = 1;
            }

            // maxLen = max(maxLen, );
            if(max(incr >> 1, min(prevI, incr)) >= k)
                return true;
        }

        return false;
    }
};