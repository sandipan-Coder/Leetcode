class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        int cuSum = 0;
        int ans = 0;

        map<int, int> diff;
        unordered_map<int, int> freq;

        for(int ele: nums){

            freq[ele]++;

            int l = max(ele - k, 0);
            int r = ele + k;

            diff[l]++;
            diff[r + 1]--;

            diff[ele] += 0;
        }

        for(auto &it: diff){

            int target = it.first;
            it.second += cuSum; 

            int noOfFreq = freq[target];
            int needConversion = diff[target] - noOfFreq;
            int maxPossibleConverion = min(needConversion, numOperations);

            ans = max(ans, noOfFreq + maxPossibleConverion);

            cuSum = it.second;
        }

        return ans;
    }
};