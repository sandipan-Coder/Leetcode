class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    bool doesAliceWin(string s) {
        
        vector<char> vowels;
        for(char ch: s){
            if(isVowel(ch))
                vowels.push_back(ch);
        }

        if(vowels.size() == 0)
            return false;
        else
            return true;
    }
};