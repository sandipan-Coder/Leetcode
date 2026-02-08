class Solution {
private:

    string generateString(string &word) {

        int arr[26] = {0};
        string str = "";

        for(char ch: word)
            arr[ch - 'a']++;
        
        for(int i = 0; i < 26; i++) {

            int freq = arr[i];
            if(freq > 0) {
                str += string(freq, (i + 'a'));
            }
        }

        return str;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        // Using (Sorting + Map) 
        // T.C :- O(N * Klog(K));
        // S.C :- O(N);
        /*
        for(int i = 0; i < n; i++) {
    
            string temp = strs[i];
    
            sort(begin(temp), end(temp));
    
            mp[temp].push_back(strs[i]);
        }
        */

        for(int i = 0; i < n; i++) {

            string word = strs[i];

            string new_word = generateString(word);
            mp[new_word].push_back(word);
        }
    
        for(auto it: mp) {
            ans.push_back(it.second);
        }
    
        return ans;
    }
};