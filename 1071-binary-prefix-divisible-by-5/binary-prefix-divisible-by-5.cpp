class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        int num = 0;
        vector<bool> ans;

        for(int ele: nums){

            num = (num * 2) + ele;
            if(num % 5)
                ans.push_back(false);
            else
                ans.push_back(true);
            num %= 5;
        }

        return ans;
    }
};