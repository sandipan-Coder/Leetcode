class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26, 0);
        int ans = 0;

        for(char ch: word){
            int idx = ch - 'a';
            freq[idx]++;
        }

        vector<pair<int, int>> idxFreq;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0)
                idxFreq.push_back({freq[i], i});
        }

        sort(idxFreq.begin(), idxFreq.end(), [](const pair<int, int> &a, const pair<int, int> &b){

            if(a.first == b.first)
                return a.second < b.second;
            
            return a.first > b.first;
        });
        int n = idxFreq.size();

        for(int i = 0; i < n; i++) {

            int div = i / 8;
            int count = idxFreq[i].first;

            ans += (count * (div + 1));
        }

        return ans;
    }
};