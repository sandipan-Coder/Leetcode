class Solution {
private:

    int reverseNum(int num) {

        int ans = 0;

        while(num) {

            int rem = (num % 10);
            ans = (ans * 10) + rem;

            num /= 10;
        }

        return ans;
    }

public:
    int mirrorDistance(int n) {
        
        int revNum = reverseNum(n);
        int diff = abs(n - revNum);

        return diff;
    }
};