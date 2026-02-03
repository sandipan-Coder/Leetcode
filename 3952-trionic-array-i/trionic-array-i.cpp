class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int n = nums.size();
        int idx = 0;

        // Increasing sequence
        while((idx < n-1) && (nums[idx] < nums[idx + 1]))
            idx++;
        
        if((idx == 0) || (idx == n-1))
            return false;
        
        // Decreasing sequence
        while((idx < n-1) && (nums[idx] > nums[idx + 1]))
            idx++;
        
        if(idx == n-1)
            return false;
        
        // Increasing sequence
        while((idx < n-1) && (nums[idx] < nums[idx + 1]))
            idx++;
        
        return (idx == n-1);
    }
};