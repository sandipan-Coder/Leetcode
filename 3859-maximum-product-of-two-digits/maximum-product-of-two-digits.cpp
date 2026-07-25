class Solution {
public:
    int maxProduct(int n) {
        
        int num = n;
        vector<int> digits;

        while(num) {

            int rem = (num % 10);
            
            digits.push_back(rem);
            num /= 10;
        }

        sort(digits.rbegin(), digits.rend());

        return (digits[0] * digits[1]);
    }
};