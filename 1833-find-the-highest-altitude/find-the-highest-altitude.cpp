class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        vector<int> altitude(n+1, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            
            altitude[i + 1] = (altitude[i] + gain[i]);
            ans = max(ans, altitude[i + 1]);
        }

        // for(int i = 0; i <= n; i++)
        //     cout << altitude[i] << " ";

        return ans;
    }
};