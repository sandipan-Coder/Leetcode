class Solution {
public:
    int partitionString(string s) {
        
        unordered_map<char, int> mp;
        int count = 0;

        for(char ch: s) {

            if(mp.count(ch)) {
                mp.clear();
                mp[ch]++;
                count++;
            } else {
                mp[ch]++;
            }
        }

        return (count + 1);
    }
};