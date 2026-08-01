class Solution {
private:

    int solve(int i, int j, vector<int>& nums){

        if(i > j)
            return 0;
        
        if(i == j)
            return nums[i];

        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));

        int take_j = nums[j] + min(solve(i, j-2, nums), solve(i+1, j-1, nums));

        return max(take_i, take_j);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int player1_score = solve(0, n-1, nums);
        int player2_score = (sum - player1_score);

        return (player1_score >= player2_score);
    }
};