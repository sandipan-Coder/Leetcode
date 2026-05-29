class Solution {
private:

    int sumOfDigit(int num) {

        int sum = 0;

        while(num) {

            int digit = (num % 10);
            sum += digit;
            num /= 10;
        }

        return sum;
    }

public:
    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for(int num: nums){

            int sum = sumOfDigit(num);
            ans = min(ans, sum);
        }

        return ans;
    }
};