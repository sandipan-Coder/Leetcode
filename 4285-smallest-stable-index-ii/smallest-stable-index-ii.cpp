class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi = 0;
        vector<int> mini(n, INT_MAX);
        mini[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--)
            mini[i] = min(mini[i + 1], nums[i]);
        

        for(int i = 0; i < n; i++){

            maxi = max(maxi, nums[i]);

            int res = (maxi - mini[i]);
            if(res <= k)
                return i;
        }

        return -1;
    }
};