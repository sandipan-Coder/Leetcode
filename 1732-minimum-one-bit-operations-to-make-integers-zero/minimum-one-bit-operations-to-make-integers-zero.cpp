class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        if(n == 0)
            return 0;
        
        int fun[31] = {0};
        fun[0] = 1;
        int ans = 0;
        bool positive = true;

        for(int i = 1; i < 31; i++)
            fun[i] = 2*fun[i - 1] + 1;
        
        for(int i = 30; i >= 0; i--){

            if(((1 << i) & n)){

                if(positive)
                    ans += fun[i];
                else
                    ans -= fun[i];
                
                positive = !positive;
            }
        }

        return ans;
    }
};