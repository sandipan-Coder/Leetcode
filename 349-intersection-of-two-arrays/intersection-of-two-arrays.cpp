class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2;

        
        for(int i = 0; i < nums2.size(); i++) {
            
            if(st1.count(nums2[i]))
                st2.insert(nums2[i]);
        }
        
        if(st2.empty())
            return {};
        
        vector<int> ans(st2.begin(), st2.end());
        sort(ans.begin(), ans.end());
        
        return ans;

    }
};