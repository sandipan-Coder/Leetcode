class Solution {
private:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        else
            return false;
    }

public:
    string sortVowels(string s) {
        
        vector<char> vowels;

        for(char ch: s){
            if(isVowel(ch))
                vowels.push_back(ch);
        }

        sort(begin(vowels), end(vowels));
        int idx = 0;

        for(char &ch: s){
            if(isVowel(ch))
               ch = vowels[idx++];
        }

        return s;
    }
};