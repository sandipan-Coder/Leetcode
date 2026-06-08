class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        vector<int>smaller;
        vector<int>greater;
        vector<int>ans;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == pivot)
                count++;
            else if(nums[i] < pivot){
                smaller.push_back(nums[i]);
            }
            else{
                greater.push_back(nums[i]);
            }
        }

        for(int i = 0; i < smaller.size(); i++)
            ans.push_back(smaller[i]);

        while(count){
            ans.push_back(pivot);
            count--;
        }
        for(int i = 0; i < greater.size(); i++)
            ans.push_back(greater[i]);
        
        return ans;
    }
};