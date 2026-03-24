class Solution {
private:

    vector<int> approach1(vector<int> &nums) {

        int n = nums.size();
        vector<int> prefix(n , 1);
        vector<int> suffix(n, 1);
        vector<int> ans(n, 1);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {

            prefix[i] = (nums[i] * prefix[i - 1]);
            suffix[n - 1 - i] = (nums[n - 1 - i] * suffix[n - i]);
        }

        ans[0] = suffix[1];
        ans[n - 1] = prefix[n - 2];
        for(int i = 1; i < n-1; i++) {

            ans[i] = (prefix[i - 1] * suffix[i + 1]);
        }

        return ans;
    }

    vector<int> approach2(vector<int> &nums) {

        int n = nums.size();
        vector<int> ans(n,1);

        for (int i = 1; i < n; i++)
            ans[i] = (ans[i-1] *nums[i-1]);
        
        int suffix = 1;
        for (int i = n-2; i >= 0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
       
        return ans;
    }

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // vector<int> ans1 = approach1(nums);
        // return ans1;

        vector<int> ans2 = approach2(nums);
        return ans2;
    }
};