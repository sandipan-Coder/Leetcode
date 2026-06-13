class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        vector<char> mp(26, '*');
        string ans = "";

        int i = 25;
        for(char ch = 'a'; ch <= 'z'; ch++){
            mp[i] = ch;
            i--;
        }

        for(string &str: words) {

            int sum = 0;
            for(char &ch: str) 
                sum += weights[ch - 'a'];
            
            sum = (sum % 26);

            ans += mp[sum];
        }

        return ans;
    }
};