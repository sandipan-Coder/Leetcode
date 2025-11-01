class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        
        long long ans = 0;
        string str = to_string(nums[0]);
        int n = str.length();
        int m = nums.size();

        for(int i = 0; i < n; i++){
            
            map<int, int> mp;
            for(int num: nums){
                string str = to_string(num);
                int digit = str[i] + '0';
                mp[digit]++;
            }

            for(auto it: mp){

                int diff = m - it.second; 
                ans += (1LL * it.second * diff);
            }
        }

        return ans / 2;
    }
};