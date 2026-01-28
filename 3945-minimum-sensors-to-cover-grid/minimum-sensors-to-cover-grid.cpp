class Solution {
private:

    int Ceil(int n, int x) {

        int ans = (n / x);

        if(n % x)
            ans++;
        
        return ans;
    }

public:
    int minSensors(int n, int m, int k) {
        
        int length = 2 * k + 1;  // This is the length covered by 1 sensor.

        return (Ceil(n, length) * Ceil(m, length));
    }
};