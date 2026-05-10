class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i = 0;
        int j = 0;
        int n = word1.length();
        int m = word2.length();
        int idx = 0;
        string ans = "";

        while(i < n && j < m){

            if(idx == 0){
                ans.push_back(word1[i]);
                i++;
            }
            else{
                ans.push_back(word2[j]);
                j++;
            }

            idx = (idx + 1) % 2;
        }

        while(i < n) {
            ans.push_back(word1[i]);
            i++;
        }

        while(j < m){
            ans.push_back(word2[j]);
            j++;
        }

        return ans;
    }
};