class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size();

        if(n == 1)
            return 0;

        int ans = 0;
        int noOfCol = strs[0].size();
        vector<int> col(noOfCol, 0);

        for(int i = 1; i < n; i++){
            string str1 = strs[i - 1];
            string str2 = strs[i];

            for(int i = 0; i < noOfCol; i++){
                if(str1[i] > str2[i])   
                    col[i] = 1;
            }
        }
        
        for(int i = 0; i < noOfCol; i++){
            if(col[i])
                ans++;
        }

        return ans;
    }
};