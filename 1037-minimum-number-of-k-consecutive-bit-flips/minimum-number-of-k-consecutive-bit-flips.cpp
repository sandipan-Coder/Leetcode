class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<bool> isFlipped(n, false);
        int flipCount = 0, currFlip = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k)
                currFlip ^= isFlipped[i - k]; // remove expired flip
        
            if ((nums[i] ^ currFlip) == 0) {  // still 0 after flips
                if (i + k > n) 
                    return -1;    // can't flip beyond bounds
                flipCount++;
                currFlip ^= 1;
                isFlipped[i] = true;
            }
        }
        
        return flipCount;
    }
};