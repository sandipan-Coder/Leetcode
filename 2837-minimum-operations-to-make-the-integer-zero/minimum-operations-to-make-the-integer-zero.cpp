class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        if(num2 > num1)
            return -1;

        for(int i = 0; i <= 60; i++){

            long long int target = num1 - i*1LL*num2;
            if(target <= 0)
                return -1;

            long long int bits = __builtin_popcountll(target);
            if(bits <= i && target >= i)
                return i;
        }

        return -1;
    }
};