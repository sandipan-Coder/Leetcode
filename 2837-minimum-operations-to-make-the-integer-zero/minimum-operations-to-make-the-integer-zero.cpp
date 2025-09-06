class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        if(num2 > num1)
            return -1;
        int op = 0;

        while(true){

            long long val = (long long)num1 - (long long)op*num2;

            if(val < 0)
                return -1;

            if(__builtin_popcountll(val) <= op && op <= val)
                return op;
            op++;
        }
        

        return -1;
    }
};