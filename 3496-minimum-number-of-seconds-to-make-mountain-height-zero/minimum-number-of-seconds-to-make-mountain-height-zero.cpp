class Solution {
private:

    bool isPossible(long long height, vector<int>& workerTimes, long long T) {

        long long currHeight = 0;

        for(auto it: workerTimes) {

            long long brokenHeight = (-1 + sqrt(1 + (8 * T) / it)) / 2;
            currHeight += brokenHeight;

            if(currHeight >= height)
                return true;
        }

        return false;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long low = 0;
        long long high = 1e18;
        long long ans = 1e18;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            if(isPossible(1LL * mountainHeight, workerTimes, mid)){
                ans = mid;
                high = mid - 1;
            } 
            else
                low = mid + 1;
        }

        return ans;
    }
};