class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = beginWord.length();
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord)
                return steps;
            
            for(int i = 0; i < n; i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.count(word)) {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};