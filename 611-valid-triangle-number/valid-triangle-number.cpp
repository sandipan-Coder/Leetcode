class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;

        for(int i = n-1; i >= 2; i--){

            int start = 0;
            int end = i - 1;
            while(start < end){

                if(nums[start] + nums[end] > nums[i]){
                    count += (end - start);
                    end--;
                }
                else
                    start++;
            }
        }

        return count;
    }
};