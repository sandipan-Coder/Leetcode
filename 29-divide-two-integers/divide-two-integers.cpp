class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor)
            return 1;
        
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) 
            return INT_MIN;

        bool sign = true; // means +ve
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;

        long long  num = llabs((long long)dividend);;
        long long divs = llabs((long long)divisor);
        long long ans = 0;

        while(num >= divs){

            int count = 0;
            while(count < 31 && num >= (divs << (count + 1)))
                count++;
            
            ans += (1LL << count);
            num -= (divs << count);
        }

        if(ans >= (1LL << 31) && sign == true)
            return INT_MAX;
        if(ans >= (1LL << 31) && sign == false)
            return INT_MIN;

        return sign ? (int)ans : (int)(-1 * ans);
    }
};