class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        unordered_set<char> brokenKey;
        vector<string> words;
        int n = text.size();
        int count = 0;

        for(char ch: brokenLetters)
            brokenKey.insert(ch);

        string temp = "";
        for(int i = 0; i < n; i++){
            if(text[i] == ' '){
                words.push_back(temp);
                temp = "";
            }
            else
                temp += text[i];
        }
        words.push_back(temp);

        for(string str: words){
            bool flag = true;
            for(int i = 0; i < str.size(); i++){
                if(brokenKey.count(str[i])){
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }

        return count;
    }
};