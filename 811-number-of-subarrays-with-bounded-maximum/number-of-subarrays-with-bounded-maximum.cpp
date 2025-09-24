class Solution {
private:

    long long countSubarrayIntoBound(vector<int>& nums, int bound){

        long long count = 0;
        long long length = 0;

        for(int ele: nums){
            if(ele <= bound){
                length++;
                count += length;
            }
            else
                length = 0;
        }

        return count;
    }

public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        return (int)(countSubarrayIntoBound(nums, right) - countSubarrayIntoBound(nums, left - 1));

    }
};