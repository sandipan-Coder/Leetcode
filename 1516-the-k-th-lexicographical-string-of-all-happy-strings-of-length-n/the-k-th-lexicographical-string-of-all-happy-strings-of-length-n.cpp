class Solution {
private:

    void solve1(int n, string &curr, vector<string> &ans) {

        if(curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {

            if(!curr.empty() && ch == curr.back())
                continue;
            
            curr.push_back(ch);
            solve1(n, curr, ans);

            curr.pop_back();
        }
    }

    string approach1(int n, int k) {
        
        string curr = "";
        vector<string> ans;

        solve1(n, curr, ans);

        if(k > ans.size())
            return "";

        return ans[k - 1];
    }

    void solve2(int n, string &curr, string &ans, int &count, int k) {

        if(curr.length() == n) {
            
            count++;
            if(count == k)
                ans = curr;

            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {

            if(!curr.empty() && ch == curr.back())
                continue;
            
            curr.push_back(ch);
            solve2(n, curr, ans, count, k);

            curr.pop_back();
        }
    }

    string approach2(int n, int k) {
        
        string curr = "";
        string ans = "";
        int count = 0;

        solve2(n, curr, ans, count, k);

        return ans;
    }

public:
    string getHappyString(int n, int k) {
        
       // Time :- O(N * 2^N).
       // Space :- O(2^N).

       //return approach1(n, k);

       // Optimize space
       // Time :- O(N * 2^N).
       // Space :- O(1).
       return approach2(n, k);

    }
};