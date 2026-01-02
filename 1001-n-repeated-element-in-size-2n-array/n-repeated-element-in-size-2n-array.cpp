class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        bitset<10001> bs;

        for(int ele: nums){

            if(bs.test(ele))
                return ele;
            
            bs.set(ele);
        }

        return -1;
    }
};