class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        int count = 0;
        int minLen = INT_MAX;
        int startIdx = -1;
        int charFreq[256] = {0};

        for(char &ch: t)
            charFreq[ch]++;
        
        int low = 0;
        int high = 0;

        while(high < n) {

            char ch = s[high];
            if(charFreq[ch] > 0)
                count++;
            
            charFreq[ch]--;
            
            while(count == m) {

                int len = high - low + 1;
                if(len < minLen) {
                    minLen = len;
                    startIdx = low;
                }

                char leftChar = s[low];
                charFreq[leftChar]++;
                if(charFreq[leftChar] > 0)
                    count--;
                
                low++;
            }

            high++;
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};