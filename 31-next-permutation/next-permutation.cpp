class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        // It store 1st smallest index from Right->Left which voilate (nums[i] < nums[i - 1])
        int smallestIdx = -1;  

        for(int i = n-1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                smallestIdx = i-1;
                break;
            }
        }

        if(smallestIdx != -1) {
            int swapIdx = smallestIdx;
            for(int i = n-1; i > smallestIdx; i--) {
                if(nums[i] > nums[smallestIdx]) {
                    swapIdx = i;
                    break;
                }
            }

            swap(nums[smallestIdx], nums[swapIdx]);
        }

        reverse(nums.begin() + smallestIdx + 1, nums.end());
    }
};