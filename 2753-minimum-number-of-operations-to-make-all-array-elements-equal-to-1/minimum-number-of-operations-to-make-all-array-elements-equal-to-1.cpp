class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        int oneCount = 0;
        int ans = nums[0];
        int minLen = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1)    
                oneCount++;
            if(i > 0)
                ans = gcd(ans, nums[i]);
        }

        if(oneCount)
            return (n - oneCount);
        
        if(ans > 1)
            return -1;
        
        for(int i = 0; i < n-1; i++){
            int ans = nums[i];
            for(int j = i+1; j < n; j++){

                ans = gcd(ans, nums[j]);
                if(ans == 1){
                    minLen = min(minLen, (j - i + 1));
                    break;
                }
            }
        }

        return (minLen + n - 2);
    }
};