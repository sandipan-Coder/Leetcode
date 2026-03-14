class Solution {
private:

    int Count(long curr, long next, int n) {

        int totalCount = 0;

        while(curr <= n) {

            totalCount += (next - curr);

            curr *= 10;
            next *= 10;

            next = min(next, (long)(n + 1));
        }

        return totalCount;
    }

public:
    int findKthNumber(int n, int k) {
        
        int curr = 1;
        k = k - 1;

        while(k) {

            int countNum = Count(curr, curr + 1, n);

            if(countNum <= k) {
                
                curr++;
                k -= countNum;
            } 
            else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }
};