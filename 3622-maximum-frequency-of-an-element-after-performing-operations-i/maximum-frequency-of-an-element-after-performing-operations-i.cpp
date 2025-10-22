class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end()) + k;
        int ans = 0;

        vector<int> diff(maxVal + 2, 0);
        unordered_map<int, int> freq;

        for(int ele: nums){

            freq[ele]++;

            int l = max(ele - k, 0);
            int r = ele + k;

            diff[l]++;
            diff[r + 1]--;
        }

        for(int i = 1; i <= maxVal; i++){

            diff[i] += diff[i - 1];

            int noOfFreq = freq[i];
            int needConversion = diff[i] - noOfFreq;
            int maxPossibleConverion = min(needConversion, numOperations);

            ans = max(ans, noOfFreq + maxPossibleConverion);
        }

        return ans;
    }
};