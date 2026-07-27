class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        sort(nums.rbegin(), nums.rend());

        int num1 = nums[0] - 1;
        int num2 = nums[1] - 1;

        return (num1 * num2);
    }
};