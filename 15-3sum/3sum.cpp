class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++) {

            if(i > 0 && (nums[i] == nums[i - 1]))
                continue;
            
            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                long long sum = (long long)(nums[i] + nums[left] + nums[right]);

                if(sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    int leftVal = nums[left];
                    int rightVal = nums[right];

                    while(left < right && nums[left] == leftVal)
                        left++;
                    while(left < right && nums[right] == rightVal)
                        right--;
                } 
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }

        return ans;
    }
};