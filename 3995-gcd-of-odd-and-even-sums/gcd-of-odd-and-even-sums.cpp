class Solution {
private:

    int findGCD(int a, int b){

        if(b == 0)
            return a;
        
        return findGCD(b, a % b);
    }

public:
    int gcdOfOddEvenSums(int n) {
        
        int oddSum = (n * n);
        int evenSum = n * (n + 1);

        int ans = findGCD(oddSum, evenSum);
        return ans;
    }
};