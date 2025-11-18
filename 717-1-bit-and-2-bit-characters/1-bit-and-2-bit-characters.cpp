class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();
        if(n == 1)
            return true;

        if(n >= 2 && bits[n - 2] == 0)
            return true;
        
        int idx = 0;
        while(idx < n-1)
            idx += bits[idx] + 1;
        
        return (idx == n-1);
    }
};