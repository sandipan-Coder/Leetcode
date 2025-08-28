class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeroCount = 0;
        int ans = INT_MIN;

        while(j < n){

            if(nums[j] == 0)
                zeroCount++;
            
            if(zeroCount > k){
                ans = max(ans, j - i);

                while(i <= j && zeroCount > k){
                    if(nums[i] == 0)
                        zeroCount--;
                    i++;
                }
            }
            j++;
        }
        
        ans = max(ans, j - i);

        return ans;
    }
};