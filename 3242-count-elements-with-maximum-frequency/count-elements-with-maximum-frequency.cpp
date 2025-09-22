class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int maxiFreq = 0;
        int count = 0;

        for(int ele: nums){
            mp[ele]++;
            maxiFreq = max(maxiFreq, mp[ele]);
        }

        for(auto it: mp){
            if(it.second == maxiFreq)
                count++;
        }

        return (count * maxiFreq);
    }
};