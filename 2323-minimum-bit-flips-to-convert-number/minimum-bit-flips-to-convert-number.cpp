class Solution {
public:
    int minBitFlips(int start, int goal) {

        int ans = start ^ goal;
        int bits = __builtin_popcount(ans);

        return bits;
    }
};