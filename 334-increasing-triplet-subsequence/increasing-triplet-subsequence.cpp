class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        int num3 = -1;

        for(int ele: nums) {

            if(ele <= num1)
                num1 = ele;
            else if(ele <= num2)
                num2 = ele;
            else
                num3 = ele;
            
            if(num3 != -1)
                return true;
        }

        return false;
    }
};