class Solution {

    unordered_map<long long, int> mp;
    string S;
    int K;
private:

    int solve(long long i, long long uniqueChars, bool canChange){
        
        long long key = ((i << 27) | (uniqueChars << 1) | canChange);

        if(mp.count(key))
            return mp[key];

        if(i >= S.length())
            return 0;
        
        int charIdx = S[i] - 'a';
        int newUniqueChars = uniqueChars | (1 << charIdx);
        int uniqueCharCount = __builtin_popcount(newUniqueChars);

        int result;

        if(uniqueCharCount > K)
            result = 1 + solve(i+1, (1 << charIdx), canChange);
        else
            result = solve(i+1, newUniqueChars, canChange);
        
        if(canChange){

            for(int newCharIdx = 0; newCharIdx < 26; newCharIdx++){

                int newUniqueSet = uniqueChars | (1 << newCharIdx);
                int newuniqueCharCount = __builtin_popcount(newUniqueSet);

                if(newuniqueCharCount > K)
                    result = max(result, 1 + solve(i+1, (1 << newCharIdx), false));
                else
                    result = max(result, solve(i+1, newUniqueSet, false));
            }
        }

        return mp[key] = result;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        
        S = s;
        K = k;

        return 1 + solve(0, 0, true);
    }
};