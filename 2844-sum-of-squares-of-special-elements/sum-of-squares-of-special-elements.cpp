class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            int idx = i + 1;
            int ele = nums[i];

            if((n % idx) == 0)
                ans += (ele * ele);
        }

        return ans;
    }
};