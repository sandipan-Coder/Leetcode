class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int count = 0;

        for(char ch: word) {

            if(isupper(ch))
                upper[ch - 'A']++;
            else
                lower[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(upper[i] && lower[i])
                count++;
        }

        return count;
    }
};