class Solution {
    vector<vector<int>> ans;
private:

    void solve(int idx, vector<int>& candidates, int target, vector<int> &temp){

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(idx >= candidates.size())
            return;
        
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            solve(idx, candidates, target - candidates[idx], temp);
            temp.pop_back();
        }

        solve(idx+1, candidates, target, temp);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        ans.clear();
        vector<int> temp;
        solve(0, candidates, target, temp);

        return ans;
    }
};