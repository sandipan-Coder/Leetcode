class Solution {
public:
    string decodeString(string s) {
        
        int number = 0;
        string word = "";
        stack<string> wordst;
        stack<int> num;

        for(int i = 0; i < s.size(); i++){

            char ch = s[i];
            if(isdigit(ch))
                number = number * 10 + (ch - '0');
            else if(isalpha(ch))
                word.push_back(ch);
            else if(ch == '['){
                wordst.push(word);
                num.push(number);
                word = "";
                number = 0;
            }
            else {
                int count = num.top();
                string seq = wordst.top();
                num.pop();
                wordst.pop();

                for(int i = 1; i <= count; i++)
                    seq.append(word);
                
                word  = seq;
            }
        }

        return word;
    }
};