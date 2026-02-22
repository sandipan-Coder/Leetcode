class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        int minIdx = 0;
        long long minDiff = INT_MAX;
        long long totalSum = 0;

        for(int num: nums)
            totalSum += num;
        
        long long leftSum = 0;
        for(int i = 0; i < n; i++) {

            int no_of_left_element = i+1;
            int no_of_right_element = (n - i - 1);

            leftSum +=  nums[i];
            long long rightSum = (totalSum - leftSum);

            long long leftAvg = (leftSum / no_of_left_element);
            long long rightAvg = (no_of_right_element > 0 ) ? (rightSum / no_of_right_element) : 0;

            long long diff = llabs(leftAvg - rightAvg);
            if(diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }

        return minIdx;
    }
};