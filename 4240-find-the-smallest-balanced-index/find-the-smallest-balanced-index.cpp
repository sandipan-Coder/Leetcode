class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        int n = nums.size();
        long long multiple = 1;
        long long totalSum = 0;

        for(int num: nums)
            totalSum += num;

        for(int i = n-1; i >= 0; i--) {
            
            totalSum -= nums[i];

            if(multiple > totalSum)
                break;
            
            if(multiple == totalSum)
                return i;
            
            multiple *= (1LL * nums[i]);
        }

        return -1;
    }
};