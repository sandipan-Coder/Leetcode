class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;

        for(int num: nums){

            string str = to_string(num);
            for(char ch: str){
                int dig = ch - '0';
                ans.push_back(dig);
            }
        }

        return ans;
    }
};