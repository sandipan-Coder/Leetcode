class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m, 0);
        vector<int> prefix(n, 0);

        sort(begin(nums), end(nums));

        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = (prefix[i - 1] + nums[i]);

        for(int i = 0; i < m; i++) {
            
            int q = queries[i];
            auto lb = upper_bound(prefix.begin(), prefix.end(), q);
            int len = (lb - prefix.begin());

            ans[i] = len;
        }

        return ans;
    }
};