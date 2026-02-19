class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n = s.length();
        if(n == 1)
            return 0;

        int curr = 1;
        int prev = 0;
        int subCount = 0;

        for(int i = 1; i < n; i++) {

            if(s[i] == s[i - 1])
                curr++;
            else {
                subCount += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }

        subCount += min(curr, prev);

        return subCount;
    }
};