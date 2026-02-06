class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        

        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n == 2 && (nums[1] > (1LL * nums[0] * k)))
            return 1;


        int ans = INT_MAX;
        int i = 0, j = 0;

        while(j < n && (nums[j] <= (1LL * nums[i] * k)))
            j++;
        
        ans = min(ans, (n - (j - i)));
        // cout << ans << endl;

        while(j < n) {

            if(nums[j] > (1LL * nums[i] * k)) {

                while(i <= j && (nums[j] > (1LL * nums[i] * k)))
                    i++;
                
            }

            ans = min(ans, (n - (j - i + 1)));
            j++;
        }

        ans = min(ans, (n - (j - i)));

        return ans;
    }
};