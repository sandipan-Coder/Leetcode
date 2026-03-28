class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int count = 0;

        for(int &num: nums){

            leftSum += num;
            if(leftSum == totalSum)
                break;

            int rightSum = totalSum - leftSum;
            if(abs(leftSum - rightSum) % 2 == 0)
                count++;
        }

        return count;
    }
};