class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int len = INT_MIN;
        unordered_map<int, int> mp;
        int count = 0;
        int prevIdx = -1;
        
        for(int i = 0; i < n; i++){

            if(nums[i] == 0){
                if(prevIdx == -1){
                    prevIdx = i;
                    mp[prevIdx] += count;
                    count = 0;
                }
                    
                else {
                    mp[prevIdx] += count;
                    mp[i] = count;
                    prevIdx = i;
                    count = 0;
                }
            }
            else
                count++;
        }

        mp[prevIdx] += count;

        for(auto it: mp){
            int freq = it.second;

            len = max(len, freq);
        }

        return (count == n) ? n-1 : len;
    }
};