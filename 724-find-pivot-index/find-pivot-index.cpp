class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0;

        for(int num: nums)
            totalSum += num;
        
        int leftSum = 0;

        for(int i = 0; i < n; i++) {
            
            if((i - 1) >= 0)
                leftSum += nums[i - 1];
            int rightSum = totalSum - (leftSum + nums[i]);

            if(leftSum == rightSum)
                return i;
        }

        return -1;
    }
};