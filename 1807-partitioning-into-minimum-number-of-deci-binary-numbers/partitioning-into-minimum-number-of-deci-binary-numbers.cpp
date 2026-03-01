class Solution {
public:
    int minPartitions(string n) {
        
        int maxDigit = 0;

        for(char ch: n) {

            int digit = ch - '0';
            maxDigit = max(maxDigit, digit);
        }

        return maxDigit;
    }
};