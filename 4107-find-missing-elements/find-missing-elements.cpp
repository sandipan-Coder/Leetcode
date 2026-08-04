class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        int maxi = 0;
        int mini = 101;

        for(int num: nums){

            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        int size = maxi - mini + 1;
        vector<bool> freq(size, false);
        for(int num: nums) {
            
            int idx = num - mini;
            freq[idx] = true;
        }

        for(int i = 0; i < size ; i++) {

            if(!freq[i]) {
                int ele = mini + i;
                ans.push_back(ele);
            }
        }

        return ans;
    }
};