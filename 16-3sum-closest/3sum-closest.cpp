class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int minSum = 0;
        int closest = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int k = 0; k < n-2; k++) {

            int i = k+1;
            int j = n-1;

            while(i < j) {

                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if(diff < closest) {
                    minSum = sum;
                    closest = diff;
                }

                if(sum < target)
                    i++;
                else
                    j--;
            }
        }

        return minSum;
    }
};