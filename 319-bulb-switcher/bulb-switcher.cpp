class Solution {
public:
    int bulbSwitch(int n) {
        
        if(n == 0 || n == 1)
            return n;
        
        int count = 0;
        int i = 1;

        while((i * i * 1LL) <= n) {
            count++;
            i++;
        }

        return count;
    }
};