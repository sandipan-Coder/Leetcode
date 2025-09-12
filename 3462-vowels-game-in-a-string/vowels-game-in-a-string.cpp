class Solution {
private:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }

public:
    bool doesAliceWin(string s) {
        
        for(char ch: s){
            if(isVowel(ch))
                return true;
        }

        return false;
    }
};