class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int one = 0;
        int two = 0;

        for(int ele: nums){

            one = (one ^ ele) & (~ two);
            two = (two ^ ele) & (~ one);
        }

        return one;
    }
};