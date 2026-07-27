class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Process - 1
        /*
        sort(nums.rbegin(), nums.rend());

        int num1 = nums[0] - 1;
        int num2 = nums[1] - 1;

        return (num1 * num2);
        */

        // Process - 2

        int num1 = 0;
        int num2 = 0;

        for(int num: nums){

            if(num >= num1){
                num2 = num1;
                num1 = num;
            }
            else if(num > num2 && num != num1)
                num2 = num;
        }

        num1--;
        num2--;

        return (num1 * num2);
    }
};