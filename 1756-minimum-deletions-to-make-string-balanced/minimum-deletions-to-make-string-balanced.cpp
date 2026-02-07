class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        // vector<int> beforeB(n, 0);
        // vector<int> afterA(n, 0);
        int count = INT_MAX;
        int total_count_A = 0;

        for(char ch: s) {
            if(ch == 'a')
               total_count_A++; 
        }

        /*
        for(int i = 1; i < n; i++) {

            if(s[i - 1] == 'b')
                beforeB[i]++;
            if(s[n - i] == 'a')
                afterA[n - i - 1]++;
            
            afterA[n - i - 1] += afterA[n - i];
            beforeB[i] += beforeB[i - 1];
        }
        */

        int leftBCount = 0;
        for(int i = 0; i < n; i++) {

            char ch = s[i];
            if(ch == 'a')
                total_count_A--;
            
            int del = leftBCount + total_count_A;
            count = min(count, del);

            if(s[i] == 'b')
                leftBCount++;
        }

        
        return count;
    }
};