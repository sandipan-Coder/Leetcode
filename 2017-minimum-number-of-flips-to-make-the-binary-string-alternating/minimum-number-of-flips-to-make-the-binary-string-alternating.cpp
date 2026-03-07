class Solution {
private:

    int approach1(string s) {
        
        int n = s.length();
        int ans = INT_MAX;

        s = (s + s);

        // We know that the answer may be in this two type
        // S1 :- "010101"
        // S2 :- "101010"

        string str1 , str2;
        for(int i = 0; i < (2 * n); i++) {

            str1 += (i % 2) ? '1' : '0';
            str2 += (i % 2) ? '0' : '1';
        }

        int flip1 = 0;
        int flip2 = 0;
        int i = 0, j = 0;

        while(j < (2 * n)) {
            
            // If bit of s[j] not match with str1[j] count of flip1 increase.
            if(s[j] != str1[j])
                flip1++;

            // If bit of s[j] not match with str2[j] count of flip2 increase.
            if(s[j] != str2[j])
                flip2++;
            
            // If the window size is bigger then the size of the string.
            if((j - i + 1 ) > n) {

                if(s[i] != str1[i])
                    flip1--;
                
                if(s[i] != str2[i])
                    flip2--;
                
                i++;
            }

            if((j - i + 1 ) == n) 
                ans = min({ans, flip1, flip2});

            j++;
        }

        return ans;
    }


    // Without change the input string
    int approach2(string s) {
            
        int n = s.length();
        int ans = INT_MAX;

        // We know that the answer may be in this two type
        // S1 :- "010101"
        // S2 :- "101010"

        string str1 , str2;
        for(int i = 0; i < (2 * n); i++) {

            str1 += (i % 2) ? '1' : '0';
            str2 += (i % 2) ? '0' : '1';
        }

        int flip1 = 0;
        int flip2 = 0;
        int i = 0, j = 0;

        while(j < (2 * n)) {
            
            // If bit of s[j] not match with str1[j] count of flip1 increase.
            if(s[j % n] != str1[j])
                flip1++;

            // If bit of s[j] not match with str2[j] count of flip2 increase.
            if(s[j % n] != str2[j])
                flip2++;
            
            // If the window size is bigger then the size of the string.
            if((j - i + 1 ) > n) {

                if(s[i % n] != str1[i])
                    flip1--;
                
                if(s[i % n] != str2[i])
                    flip2--;
                
                i++;
            }

            if((j - i + 1 ) == n) 
                ans = min({ans, flip1, flip2});

            j++;
        }

        return ans;
    }

public:
    int minFlips(string s) {
        
        // Approach 1
        // Time :- O(N).
        // Space :- O(2 * N).

        /*
        return approach1(s);
        */

        return approach2(s);

    }
};