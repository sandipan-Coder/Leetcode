class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    bool doesAliceWin(string s) {
        
        int vowels = 0;
        for(char ch: s){
            if(isVowel(ch))
                vowels++;
        }

        if(vowels == 0)
            return false;
        else
            return true;
    }
};