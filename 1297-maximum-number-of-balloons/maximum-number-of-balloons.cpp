class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        vector<int> freq(26, 0);
        string str = "ablno";
        int count = text.length();

        for(char ch: text) {
            int idx = ch - 'a';
            freq[idx]++;
        }

        for(char ch: str) {
            if(ch == 'a' || ch == 'b' || ch == 'n')
                count = min(count, freq[ch - 'a']);
            else {
                int total = freq[ch - 'a'];
                total /= 2;
                count = min(count, total);
            }
        }

        return count;
    }
};