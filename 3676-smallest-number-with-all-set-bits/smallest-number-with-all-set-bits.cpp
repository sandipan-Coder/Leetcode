class Solution {
public:
    int smallestNumber(int n) {
        
        int res[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};

        int noOfBits = bit_width(static_cast<unsigned int>(n));

        return res[noOfBits - 1];
    }
};