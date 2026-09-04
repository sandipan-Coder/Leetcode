class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> maxi(n, 0);
        vector<int> mini(n, INT_MAX);

        for(int i = 0; i < n; i++){
            
            if(i == 0){
                maxi[i] = nums[i];
                mini[n - 1] = nums[n - 1];
            }
            else {
                maxi[i] = max(maxi[i - 1], nums[i]);
                mini[n - 1 - i] = min(mini[n - i], nums[n - 1 - i]);
            }
        }

        for(int i = 0; i < n; i++){

            int res = (maxi[i] - mini[i]);

            if(res <= k)
                return i;
        }

        return -1;
    }
};