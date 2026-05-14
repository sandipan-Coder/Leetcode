class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        int maxi = nums[n - 1];

        if(n != (maxi + 1))
            return false;
        
        for(int i = 0; i < n-1; i++) {
            
            if(i < n-2 && (nums[i] + 1 != nums[i + 1]))
                return false;
            
            if((i == (n-2)) && (nums[i] != nums[i + 1]))
                return false;
        }

        return true;
    }
};