class Solution {

private:
 
    int GCD_calculate(int a, int b){

        if(b == 0)
            return a;
        
        return GCD_calculate(b, a % b);
    }

public:
    int findGCD(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int &ele: nums){

            maxi = max(maxi, ele);
            mini = min(mini, ele);
        }

        int ans = GCD_calculate(maxi, mini);

        return ans;
    }
};