class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long xorOfAll = 0;
        for(int num: nums)
            xorOfAll ^= num;
        
        // Find the right most set bit of xorall.
        int rightMost = (xorOfAll & (xorOfAll - 1)) ^ xorOfAll;
        int ans1 = 0, ans2 = 0;

        for(int num: nums){

            if(num & rightMost)
                ans1 ^= num;
            else
                ans2 ^= num;
        }

        return {ans1, ans2};
    }
};