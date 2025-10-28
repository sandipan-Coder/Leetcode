class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        int ls = 0;
        int cases = 0;

        for (int num : nums) {
            int rs = total - ls - num;
            if (num == 0) {
                if (ls == rs)
                    cases += 2;
                else if (abs(ls - rs) == 1)
                    cases++;
            }
            ls += num;
        }
        
        return cases;
    }
};