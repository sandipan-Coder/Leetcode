class Solution {
public:
    long long sumAndMultiply(int n) {
        
        string str = to_string(n);
        long long num = 0;
        long long sum = 0;

        for(char ch: str) {

            if(ch != '0'){
                int digit = ch - '0';
                num = (num * 10) + digit;
                sum += digit;
            }
        }

        return (num * sum);
    }
};