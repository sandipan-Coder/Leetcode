class Solution {
private:

    void helper(string &str, char x, char y, int &maxLen) {

        int n = str.length();
        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = -1;

        for(int i = 0; i < n; i++) {

            if(str[i] == x) 
                sum++;
            else if(str[i] == y)
                sum--;
            else {
                mp.clear();
                mp[0] = i;
                sum = 0;
                continue;
            }

            if(mp.count(sum)) 
                maxLen = max(maxLen, (i - mp[sum]));
            else
                mp[sum] = i;
        }

        return;
    }

public:
    int longestBalanced(string s) {
        
        int n = s.length();
        int maxLen = 1;

        // CASE 1 :- Maxlen of all single character
        int len = 1;
        for(int i = 1; i < n; i++) {

            if(s[i] == s[i - 1])
                len++;
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        maxLen = max(maxLen, len);


        // CASE 2 :- Maxlen for 2 distinct characters
        helper(s, 'a', 'b', maxLen);
        helper(s, 'b', 'c', maxLen);
        helper(s, 'a', 'c', maxLen);


        // CASE 3 :- Maxlen for 3 distinct characters
        map<pair<int, int>, int> mp;
        int freq[3] = {0};
        mp[{0, 0}] = -1;

        for(int i = 0; i < n ; i++) {
            
            freq[s[i] - 'a']++;

            int countAB = freq[0] - freq[1];
            int countAC = freq[0] - freq[2];

            if(mp.count({countAB, countAC}))
                maxLen = max(maxLen, (i - mp[{countAB, countAC}]));
            else
                mp[{countAB, countAC}] = i;
        }

        return maxLen;
    }
};