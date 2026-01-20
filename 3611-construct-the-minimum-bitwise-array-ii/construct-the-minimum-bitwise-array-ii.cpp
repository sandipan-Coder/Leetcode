class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {

            int num = nums[i];
            if(num == 2)
                continue;
            
            for(int j = 0; j < 32; j++) {

                if((num & (1 << j)) == 0) {

                    int prev = j - 1;
                    int reqNum = (num ^ (1 << prev));

                    ans[i] = reqNum;
                    break;
                }
            }
        }

        return ans;
    }
};