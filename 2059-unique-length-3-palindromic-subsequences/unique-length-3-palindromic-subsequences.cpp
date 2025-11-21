class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int ans = 0;

        for(char ch = 'a'; ch <= 'z'; ch++){

            int firstIdx = s.find_first_of(ch);
            int lastIdx = s.find_last_of(ch);

            if(firstIdx == string::npos || firstIdx == lastIdx)
                continue;
            
            int charMusk = 0;

            for(int i = firstIdx + 1; i < lastIdx; i++){

                int charIdx = s[i] - 'a'; // a -> 0, b -> 1, c -> 2

                if(((charMusk >> charIdx) & 1) == 0){
                    
                    charMusk |= (1 << charIdx);
                    ans++;
                }
            }
        }

        return ans;
    }
};