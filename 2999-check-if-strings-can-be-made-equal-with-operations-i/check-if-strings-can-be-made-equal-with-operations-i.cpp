class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        if(s1 == s2)   
            return true;
        
        for(int i = 0; i < 4; i++) {
            if(s1[i] == s2[i])
                continue;
            else {
                if(i < 2 && (s1[i] != s2[i + 2] || s1[i + 2] != s2[i]))
                    return false;
                else if(i > 1 && (s1[i] != s2[i - 2] || s1[i - 2] != s2[i]))
                    return false;
            }
        }

        return true;
    }
};