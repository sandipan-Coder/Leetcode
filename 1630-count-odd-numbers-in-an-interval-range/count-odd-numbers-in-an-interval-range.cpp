class Solution {
public:
    int countOdds(int low, int high) {
        
        if((high - low + 1) % 2)
            return (((high - low + 1) / 2) + ((high % 2 != 0) ? 1 : 0));
        
        return (high - low + 1) / 2;
    }
};