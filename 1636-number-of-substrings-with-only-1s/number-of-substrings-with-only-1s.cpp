class Solution {
public:
    int numSub(string s) {
        
        int n = s.length();
        int ans = 0;
        int MOD = 1e9 + 7;

        int idx = 0;

        while(idx < n){

            if(s[idx] == '1'){
                int count = 0;

                while(idx < n && s[idx] == '1'){
                    count++;
                    idx++;
                }

                int cal = ((1LL * count * ((count + 1) % MOD)) % MOD / 2) % MOD;
                ans = (ans + cal) % MOD;
            }
            idx++;
        }

        return ans;
    }
};