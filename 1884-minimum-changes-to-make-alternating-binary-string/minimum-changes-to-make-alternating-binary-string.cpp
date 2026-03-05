class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length();
        string s1 = "";
        string s2 = "";
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n; i++) {

            if(i % 2) {
                s1 += '1';
                s2 += '0';
            }
            else {
                s1 += '0';
                s2 += '1';
            }
        }

        for(int i = 0; i < n; i++) {

            if(s[i] != s1[i])
                count1++;
            
            if(s[i] != s2[i])
                count2++;
        }

        return min(count1, count2);
    }
};