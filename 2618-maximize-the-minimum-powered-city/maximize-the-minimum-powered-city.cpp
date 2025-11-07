class Solution {
private:

    bool check(long long power, vector<int> stations, int r, int k) {
        int n = stations.size();

        long long p = 0;

        for (int i = 0; i < r; i++) {
            p += stations[i];
        }

        vector<int> add(n, 0);
      
        for (int i = 0; i < n; i++) {
            
            if (i + r < n  ) {
                p += stations[i + r];
                
            }
            if (i - r - 1 >= 0) {
                p -= (stations[i - r - 1]+add[i-r-1]);
            }

            



            if (p < power) {
                long long extra = power - p;
                

                if (k < extra) {
                    return false;
                }

                k -= extra;
                p+=extra;
                add[min(i + r, n - 1)] += extra;
            }
        }

        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        
        long long low = 0;
        long long high = 1e18;
        long long ans = 0;

        check(9,stations,r,k);
      

        while (low <= high) {

            long long mid = (low + high) / 2;

            if (check(mid, stations, r, k)) {
                low = mid + 1;
                ans = max(ans, mid);
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};