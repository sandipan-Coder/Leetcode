class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int, greater<>> ms;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < k; i++)
            ms.insert(nums[i]);

        int maxi = *ms.begin();
        ans.push_back(maxi);

        for(int i = k; i < n; i++){
            
            ms.insert(nums[i]);
            int out = nums[i - k];
            ms.erase(ms.find(out));
            int maxi = *ms.begin();
            ans.push_back(maxi);
        }

        return ans;
    }
};