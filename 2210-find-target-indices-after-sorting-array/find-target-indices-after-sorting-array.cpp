class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int n = nums.size();
        int count = 0;
        int smallest = 0;
        vector<int> ans;

        for(int &ele: nums){

            if(ele == target)
                count++;
            
            if(ele < target)
                smallest++;
        }

        if(count == 0)
            return ans;
        
        int idx = (smallest - 1);
    
        while(count){

            idx++;
            ans.push_back(idx);
            count--;
        }

        return ans;
    }
};