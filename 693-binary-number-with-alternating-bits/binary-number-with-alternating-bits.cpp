class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int prevBit = -1;

        while(n) {

            int bit = (n % 2);
            n /= 2;

            if(prevBit == -1)
                prevBit = bit;
            else if(prevBit == bit)
                return false;
            else
                prevBit = bit;
        }

        return true;
    }
};