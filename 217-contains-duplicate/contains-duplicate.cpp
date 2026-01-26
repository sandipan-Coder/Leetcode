class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        for(int ele: nums) {

            if(mp.count(ele))
                return true;
            
            mp[ele]++;
        }

        return false;
    }
};