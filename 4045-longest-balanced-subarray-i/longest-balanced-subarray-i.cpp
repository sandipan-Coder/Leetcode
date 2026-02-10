class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        int length = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> oddSt;
            unordered_set<int> evenSt;

            for(int j = i; j < n; j++) {

                if(nums[j] % 2)
                    oddSt.insert(nums[j]);
                else
                    evenSt.insert(nums[j]);
                
                if(oddSt.size() == evenSt.size())
                    length = max(length, (j - i + 1));
            }
        }

        return length;
    }
};