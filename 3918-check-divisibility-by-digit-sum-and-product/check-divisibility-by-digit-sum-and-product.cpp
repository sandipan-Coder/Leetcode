class Solution {
private:

    int evalute(int num){

        int sum = 0;
        int mul = 1;

        while(num) {

            int rem = num % 10;
            sum += rem;
            mul *= rem;

            num /= 10;
        }

        return (sum + mul);
    }

public:
    bool checkDivisibility(int n) {

        int total = evalute(n);

        return (n % total == 0);
    }
};