class Solution {
private:

    int productOfDigit(int num) {

        int pro = 1;

        while(num) {
            
            int dig = (num % 10);
            num /= 10;

            pro *= dig;
        }

        return pro;
    }

public:
    int smallestNumber(int n, int t) {
        
        int num = n;
        
        while(true) {

            int product = productOfDigit(num);

            if(product % t == 0)
                break;

            num++;
        }

        return num;
    }
};