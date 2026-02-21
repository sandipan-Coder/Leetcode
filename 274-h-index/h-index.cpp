class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        // Solve this problem using Counting sort
        // T.C :- O(N)
        // S.C :- O(N)

        int n = citations.size();
        vector<int> freq(n + 1, 0);

        for(int ele: citations) {

            if(ele >= n)
                freq[n]++;
            else
                freq[ele]++;
        }

        int countOfPages = freq[n];
        int idx = n;  // Maximum possible H-Index.

        while(countOfPages < idx) {

            idx--;
            countOfPages += freq[idx];
        }

        return idx;
    }
};