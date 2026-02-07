class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        vector<int> beforeB(n, 0);
        vector<int> afterA(n, 0);
        int count = INT_MAX;

        for(int i = 1; i < n; i++) {

            if(s[i - 1] == 'b')
                beforeB[i]++;
            if(s[n - i] == 'a')
                afterA[n - i - 1]++;
            
            afterA[n - i - 1] += afterA[n - i];
            beforeB[i] += beforeB[i - 1];
        }

        for(int i = 0; i < n; i++) {

            int del = beforeB[i] + afterA[i];
            count = min(count, del);
        }

        
        return count;
    }
};