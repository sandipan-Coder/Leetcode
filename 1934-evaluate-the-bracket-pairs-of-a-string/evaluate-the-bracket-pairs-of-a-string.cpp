class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        int n = s.length();
        unordered_map<string, string> mp;
        string ans = "";

        for(auto it: knowledge)
            mp[it[0]] = it[1];
        
        int idx = 0;
        while(idx < n){

            if(s[idx] == '('){

                idx++;
                string str = "";

                while(s[idx] != ')'){
                    str += s[idx];
                    idx++;
                }

                if(mp[str] != ""){
                    string val = mp[str];
                    ans += val;
                }
                else
                    ans += '?';

            }
            else
                ans.push_back(s[idx]);

            idx++;
        }

        return ans;
    }
};