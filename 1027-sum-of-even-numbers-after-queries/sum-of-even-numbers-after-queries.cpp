class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = queries.size();
        vector<int> ans(n, 0);
        int totalEvenSum = 0;

        for(int num: nums) {

            if(num % 2 == 0)
                totalEvenSum += num;
        }

        for(int i = 0; i < n; i++) {

            int val = queries[i][0];
            int idx = queries[i][1];

            int sum = nums[idx] + val;
            if((nums[idx] % 2 != 0) && (sum % 2 == 0))
                totalEvenSum += sum;
            else if((nums[idx] % 2 == 0) && (sum % 2 != 0))
                totalEvenSum -= nums[idx];
            else if((nums[idx] % 2 == 0) && (sum % 2 == 0)) 
                totalEvenSum += val;
            
            ans[i] = totalEvenSum;
            nums[idx] = sum;
        }

        return ans;
    }
};