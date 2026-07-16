class Solution {
private:

    long long findGCD(long long a, long long b){

        if(b == 0)
            return a;
        
        return findGCD(b, a % b);
    }

public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<long long> prefixGCD(n, 0);
        int maxi = INT_MIN;
        long long ans = 0;

        for(int i = 0; i < n; i++) {

            int num = nums[i];
            maxi = max(maxi, num);

            long long gcd = findGCD(num, maxi);
            prefixGCD[i] = gcd;
        }

        sort(prefixGCD.begin(), prefixGCD.end());
        int i = 0;
        int j = n - 1;

        while(i < j) {

            long long num1 = prefixGCD[i];
            long long num2 = prefixGCD[j];

            long long gcd = findGCD(num1, num2);
            ans += gcd;

            i++;
            j--;
        }

        return ans;
    }
};