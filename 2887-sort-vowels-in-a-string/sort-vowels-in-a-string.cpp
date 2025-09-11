class Solution {
public:
    string sortVowels(string s) {
        
        int n = s.length();
        string res = "";
        vector<char> vowels;

        for(char ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                vowels.push_back(ch);
        }

        sort(begin(vowels), end(vowels));
        int idx = 0;

        for(char ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                res += vowels[idx++];
            else
                res += ch;
        }

        return res;
    }
};