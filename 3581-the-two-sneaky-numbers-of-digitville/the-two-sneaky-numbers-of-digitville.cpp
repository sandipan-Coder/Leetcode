class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        vector<int> ans;
        bitset<101> vis;
        if(nums.size() == 2)
            return ans;
        
        for(int &ele: nums){

            if(vis[ele])
                ans.push_back(ele);
            
            vis[ele] = 1;
        }

        // sort(ans.begin(), ans.end());
        return ans;
    }
};