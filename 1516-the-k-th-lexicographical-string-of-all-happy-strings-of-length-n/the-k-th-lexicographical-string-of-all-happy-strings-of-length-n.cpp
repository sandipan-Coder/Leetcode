class Solution {
private:

    void solve(int n, string &curr, vector<string> &ans) {

        if(curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {

            if(!curr.empty() && ch == curr.back())
                continue;
            
            curr.push_back(ch);
            solve(n, curr, ans);

            curr.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {
        
        string curr = "";
        vector<string> ans;

        solve(n, curr, ans);

        if(k > ans.size())
            return "";

        return ans[k - 1];
    }
};