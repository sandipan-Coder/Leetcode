class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();
        int len = 0;
        vector<int> countOnes;
        int count = 0;

        for(int ele: nums){

            if(ele == 1)
                count++;
            else {
                countOnes.push_back(count);
                count = 0;
            }
        }

        countOnes.push_back(count);

        if(countOnes.size() == 1)
            return n - 1;

        for(int i = 0; i < countOnes.size() - 1; i++)
            len = max(len, countOnes[i] + countOnes[i + 1]);

        return len;
    }
};