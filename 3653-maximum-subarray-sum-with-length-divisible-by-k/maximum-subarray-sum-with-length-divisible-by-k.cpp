class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long ans = LLONG_MIN;

        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        for(int start = 0; start < k; start++){

            long long curSum = 0;
            int idx = start;

            while(idx < n && (idx + k - 1) < n){

                int j = idx + k - 1;

                long long subArraySum = prefixSum[j] - (idx != 0 ? prefixSum[idx - 1] : 0);
                
                curSum = max(subArraySum, curSum + subArraySum);
                ans = max(ans, curSum);

                idx += k;
            }
        }

        return ans;
    }
};