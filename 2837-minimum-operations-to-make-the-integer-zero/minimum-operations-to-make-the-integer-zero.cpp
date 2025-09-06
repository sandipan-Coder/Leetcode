class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        if(num2 > num1)
            return -1;

        for(int op = 1; op <= 36; op++){

            long long val = (long long)num1 - (long long)op*num2;
            if(val < 0)
                return -1;

            if(__builtin_popcountll(val) <= op && op <= val)
                return op;
        }

        return -1;
    }
};