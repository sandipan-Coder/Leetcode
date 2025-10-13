class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;

        ans.push_back(words[0]);

        for(int i = 1; i < words.size(); i++){

            string str1 = words[i];
            string str2 = ans.back();

            sort(str1.begin(), str1.end());
            sort(str2.begin(), str2.end());

            if(str1 != str2)
                ans.push_back(words[i]);
        }

        return ans;
    }
};