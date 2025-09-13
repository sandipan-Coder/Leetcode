class Solution {
public:
    int maxFreqSum(string s) {
        
        int frequency[26] = {0};
        int maxiVowel = 0;
        int maxiConsonant = 0;

        auto isVowel = [](char ch){
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };

        for(char ch: s){

            frequency[ch - 'a']++;
            if(isVowel(ch))
                maxiVowel = max(maxiVowel, frequency[ch - 'a']); 
            else
                maxiConsonant = max(maxiConsonant, frequency[ch - 'a']);
        }

        return (maxiVowel + maxiConsonant);
    }
};