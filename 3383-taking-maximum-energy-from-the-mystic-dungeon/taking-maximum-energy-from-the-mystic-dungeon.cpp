class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        int n = energy.size();
        int ans = INT_MIN;

        for(int i = n-1-k; i >= 0; i--)
            energy[i] += energy[i + k];
        
        for(int ele: energy)
            ans = max(ans, ele);

        return ans;
    }
};