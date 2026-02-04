class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int currLen = 0;
        int ans = INT_MIN;

        for(int ele: nums) {

            if(ele == 0) {
                ans = max(ans, currLen);
                currLen = 0;
            } else 
                currLen++;
        }

        ans = max(ans, currLen);

        return ans;
    }
};