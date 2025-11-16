class Solution {
public:
    int numSub(string s) {
        
        int n = s.length();
        int ans = 0;
        int MOD = 1e9 + 7;

        int idx = 0;
        int count = 0;

        while(idx < n){

            if(s[idx] == '1'){

                while(idx < n && s[idx] == '1'){
                    count++;
                    ans = (ans + count) % MOD;
                    idx++;
                }
            }
            else{
                count = 0;
                idx++;
            }
        }

        return ans;
    }
};