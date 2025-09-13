class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // Process :- 1
        /*
            int ans = 0;
            int n = nums.size();

            for(int bit = 0; bit < 32; bit++){
                int count = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i] & (1 << bit))
                        count++;
                }

                if(count % 3)
                    ans |= (1 << bit);
            }

            return ans;
        */

        // Process :- 2

            sort(nums.begin(), nums.end());
            int n = nums.size();
            for(int i = 1; i < n; i += 3){
                if(nums[i] != nums[i - 1])
                    return nums[i - 1];
            }

            return nums[n - 1];


        // Process :- 3
        /*
        int one = 0;
        int two = 0;
        for(int ele: nums){

            one = (one ^ ele) & (~ two);
            two = (two ^ ele) & (~ one);
        }

        return one;
        */
    }
};