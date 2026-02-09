class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n = changed.size();
        if(n & 1)
            return {};
        
        vector<int> ans;
        unordered_map<int, int> mp;

        sort(changed.begin(), changed.end());

        for(int ele: changed)
            mp[ele]++;
        
        for(int ele: changed) {

            if(mp[ele] == 0)
                continue;
            
            int twoTimes = (ele * 2);
            if(mp[twoTimes] == 0)
                return {};
            
            mp[ele]--;
            mp[twoTimes]--;

            ans.push_back(ele);
        }

        return ans;
    }
};