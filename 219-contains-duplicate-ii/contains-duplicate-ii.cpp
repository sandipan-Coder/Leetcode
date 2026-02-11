class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(k == 0)
            return false;
        
        int n = nums.size();
        if(n == 1)
            return false;
        unordered_map<int, int> mp;

        for(int i = 0; i <= min(k, n-1); i++) {

            if(mp.count(nums[i]))
                return true;
            
            mp[nums[i]]++;
        }

        for(int i = k+1; i < n; i++) {

            int deleteElement = nums[i - k - 1];
            mp[deleteElement]--;
            if(mp[deleteElement] == 0)
                mp.erase(deleteElement);
            
            if(mp.count(nums[i]))
                return true;
            
            mp[nums[i]]++;
        }

        return false;
    }
};