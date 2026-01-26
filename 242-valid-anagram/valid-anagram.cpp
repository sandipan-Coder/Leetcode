class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
            return false;
        
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        for(int i = 0; i < s.length(); i++){
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }

        return (freqS == freqT);
    }
};