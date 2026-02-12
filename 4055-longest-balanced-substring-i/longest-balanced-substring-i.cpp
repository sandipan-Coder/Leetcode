class Solution {
private:

    bool isBallanced(vector<int> &freq) {

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(freq[i] == 0)
                continue;
            
            if(count == 0)
                count = freq[i];
            else if(count != freq[i])
                return false;
        }

        return true;
    }

public:
    int longestBalanced(string s) {
        
        int n = s.length();
        int maxLen = 1;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                
                freq[s[j] - 'a']++;
                if(isBallanced(freq))
                    maxLen = max(maxLen, (j - i + 1));
            }
        }

        return maxLen;
    }
};