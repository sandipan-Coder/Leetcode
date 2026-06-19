class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        int prevAlt = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            
            int currAlt = (prevAlt + gain[i]);
            ans = max(ans, currAlt);
            prevAlt = currAlt;
        }

        return ans;
    }
};