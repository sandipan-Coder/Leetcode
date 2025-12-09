class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, long> left;
        unordered_map<int, long> right;
        int count = 0;
        int MOD = 1e9 + 7;

        for(int i = 1; i < n; i++)
            right[nums[i]]++;
        
        left[nums[0]]++;

        for(int i = 1; i < n; i++){

            right[nums[i]]--;
            if(right[nums[i]] == 0)
                right.erase(nums[i]);
            
            int req = nums[i] * 2;

            if(left.count(req) && right.count(req)){
                int cal = (left[req] * right[req] * 1LL) % MOD;

                count = (count + cal) % MOD;
            }

            left[nums[i]]++; 
        }

        return count;
    }
};