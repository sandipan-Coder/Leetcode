class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(), nums.end());
        int low = 0, high = n-1;

        while(low < high) {

            ans = max(ans, (nums[low] + nums[high]));
            low++;
            high--;
        }

        return ans;
    }
};