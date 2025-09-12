class Solution {
    vector<int> target;
    vector<int> window;
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        if(m > n)
            return ans;

        target.assign(26, 0);
        window.assign(26, 0);
            
        // Count frequencies of each character in the string P.
        for(char ch: p)
            target[ch - 'a']++;

        // Check the first window of size m which has same frequencies character or not.
        for(int i = 0; i < m; i++)
            window[s[i] - 'a']++;
        
        // Check if the substring is Anagram or not
        if(target == window)
            ans.push_back(0);

        // Check if the remaining string has any Anagram or not.
        for(int i = m; i < n; i++){

            // Delete the last window element
            window[s[i - m] - 'a']--;
            // Add element this window
            window[s[i] - 'a']++;

            // Check if this substring is Anagram or not.
            if(target == window)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};