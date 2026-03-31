class Solution {
private:

    bool isSame(string &word, string &str, int idx, int &len) {

        for(int i = 0; i < len; i++) {
            if(word[idx + i] != str[i])
                return false;
        }

        return true;
    }

public:
    string generateString(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        string word(N, '#');
        vector<bool> canChange(N, false);

        // Process all 'T'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {

                    if(word[i + j] != '#' && word[i + j] != str2[j])
                        return "";
                    
                    word[i + j] = str2[j];
                }
            }
        }

        // Replace the remaining spaces with 'a'
        for(int i = 0; i < N; i++) {
            if(word[i] == '#') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }


        // Process all 'F'
        for(int i = 0; i < n; i++){

            if(str1[i] == 'F' && isSame(word, str2, i, m)) {

                bool changeChar = false;
                for(int j = (i + m - 1); j >= i; j--) {

                    if(canChange[j]) {
                        word[j] = 'b';
                        changeChar = true;
                        break;
                    }
                }

                if(!changeChar)
                    return "";
            }
        }

        return word;
    }
};