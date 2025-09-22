class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;  // store indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // remove indices outside window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // record max after first k-1 steps
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};