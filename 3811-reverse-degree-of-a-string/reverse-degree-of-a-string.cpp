class Solution {
public:
    int reverseDegree(string s) {
        
        int n = s.length();
        int sum = 0;

        for(int i = 0; i < n; i++){

            int idx = s[i] - 'a';
            int pos = 26 - idx;
            int rPos = (i + 1);

            int mul = (pos * rPos);
            sum += mul;
        }

        return sum;
    }
};