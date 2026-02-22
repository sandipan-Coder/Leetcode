class Solution {
public:
    int binaryGap(int n) {

        int ans = 0;
        int prev = -1;

        for(int i = 0; i < 32; i++){

            if((n & (1 << i))) {

                if(prev != -1) 
                    ans = max(ans, abs(i - prev));
                
                prev = i;
            }
        }

        return ans;
    }
};