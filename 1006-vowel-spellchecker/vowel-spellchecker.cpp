class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        //  make lowercase
        auto toLower = [](const string &str){
            string tStr = str;

            for(char &ch: tStr)
                ch = tolower(ch);
            
            return tStr;
        };

        //  replace vowels with '*'
        auto maskVowel = [&](const string &str){
            string tStr = str;

            for(char &ch: tStr){
                char lc = tolower(ch);
                if(lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                    ch = '*';
                else
                    ch = lc;
            }

            return tStr;
        };

        //  exact words
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        //  first lowercase match for each unique lowercase word
        unordered_map<string, string> caseMap;
        for(string &word: wordlist){
            string lowerWord = toLower(word);
            if(!caseMap.count(lowerWord))
                caseMap[lowerWord] = word;
        }
        

        //  first vowel-masked match
        unordered_map<string,string> vowelMap;
        for(string &word: wordlist){
            string wordVowel = maskVowel(word);
            if(!vowelMap.count(wordVowel))
                vowelMap[wordVowel] = word;
        }
        

        //  answer queries
        vector<string> ans;
        for(string &query: queries){
            if(exact.count(query)){
                ans.push_back(query);
                continue;
            }

            string lowerCase = toLower(query);
            if(caseMap.count(lowerCase)){
                ans.push_back(caseMap[lowerCase]);
                continue;
            }

            string wordVowel = maskVowel(query);
            if(vowelMap.count(wordVowel)){
                ans.push_back(vowelMap[wordVowel]);
                continue;
            }

            ans.push_back("");
        }
        

        return ans;
    }
};