class Solution {
private:

    int approach1(string s){

        unordered_map<char, int> mp;
        int sum = 0;
        string alphabes = "abcdefghijklmnopqrstuvwxyz";
        string numbers = "0123456789";

        for(char ch: s)
            mp[ch]++;

        for(char ch: s){

            if(isalpha(ch)) {
                int mIdx = 25 - (ch - 'a');
                char mCh = alphabes[mIdx];
                int diff = abs(mp[ch] - mp[mCh]);
                sum += diff;
                mp[ch] = 0;
                mp[mCh] = 0;
            } 
            else {
                
                int mIdx = 9 - (ch - '0');
                char mCh = numbers[mIdx];
                int diff = abs(mp[ch] - mp[mCh]);
                sum += diff;
                mp[ch] = 0;
                mp[mCh] = 0;
            }
        }

        return sum;
    }

    int approach2(string s){

        unordered_map<char, int> mp;
        int sum = 0;

        for(char ch: s)
            mp[ch]++;
        
        // Character count
        for(char ch = 'a'; ch <= 'z'; ch++) 
            sum += abs(mp[ch] - mp['z' - ch + 'a']);
        
        // Digit count
        for(char ch = '0'; ch <= '9'; ch++)
            sum += abs(mp[ch] - mp['9' - ch + '0']);
        
        return (sum / 2);
    }


public:
    int mirrorFrequency(string s) {

        /*
        return approach1(s);
        */

        return approach2(s);
    }
};