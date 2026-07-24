class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int maxi = 0;
        for (int v : nums)
            maxi = max(maxi, v);
    
        int u = 1;
        while (u <= maxi)
            u <<= 1;
    
        vector<int> one(u), two(u), three(u);
        for (int v : nums) {
            one[v] = 1;
            for (int x = 0; x < u; x++) {
                if (one[x])
                    two[x ^ v] = 1;
            }
        }

        for (int v : nums) {
            for (int x = 0; x < u; x++) {
                if (two[x])
                    three[x ^ v] = 1;
            }
        }

        int ans = 0;
        for (int x = 0; x < u; x++) {
            if (three[x])
                ans++;
        }

        
        return ans;
    }
};