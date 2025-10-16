class Solution {
public:
    string toHex(int num) {
        
        string hexval = "0123456789abcdef";
        string ans = "";

        unsigned int n = static_cast< unsigned int > (num);

        if(n == 0)
            return "0";
        
        while(n > 0){

            int rem = n % 16;
            ans = hexval[rem] + ans;
            n /= 16;
        }

        return ans;
    }
};