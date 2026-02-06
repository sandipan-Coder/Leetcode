class Solution {
public:
    int bulbSwitch(int n) {
        
        if(n == 0)
            return 0;
        
        int count = 0;
        int i = 1;

        while((i * i * 1LL) <= n) {
            count++;
            i++;
        }

        return count;
    }
};