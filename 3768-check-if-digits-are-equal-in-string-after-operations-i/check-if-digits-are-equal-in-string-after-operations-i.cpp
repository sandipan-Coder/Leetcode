class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.size() > 2){

            string res = "";
            for(int i = 1; i < s.size(); i++){

                int first = s[i - 1] - '0';
                int second = s[i] - '0';

                int cal = (first + second) % 10;
                res.push_back(cal + '0');

            }

            s = res;
        }

        return (s[0] == s[1]);
    }
};