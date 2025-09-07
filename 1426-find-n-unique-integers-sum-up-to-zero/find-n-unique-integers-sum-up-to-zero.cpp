class Solution {
public:
    vector<int> sumZero(int n) {
        
        if(n == 1)
            return {0};
        int mid = n / 2;
        vector<int> ans;

        for(int i = mid; i >= (-mid); i--){

            if(i == 0){
                if(n % 2)
                    ans.push_back(i);
                else
                    continue;
            }
            else
                ans.push_back(i);
        }

        return ans;
    }
};