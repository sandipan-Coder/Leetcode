class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        
        int n = complexity.size();
        int MOD = 1e9 + 7;
        long ans = 1;

        for(int i = 1; i < n; i++){

            if(complexity[i] <= complexity[0])
                return 0;
            
            ans = (ans * i * 1LL) % MOD;
        }

        return ans;
    }
};