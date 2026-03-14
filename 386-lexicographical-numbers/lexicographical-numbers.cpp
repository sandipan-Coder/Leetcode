class Solution {
private:

    void solve(int currNum, int n, vector<int> &ans) {

        if(currNum > n)
            return;
        
        ans.push_back(currNum);

        for(int append = 0; append <= 9; append++) {

            int new_num = (currNum * 10) + append;

            if(new_num > n)
                return;
            
            solve(new_num, n, ans);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        
        for(int startNum = 1; startNum <= 9; startNum++) 
            solve(startNum, n, ans);
        
        return ans;
    }
};