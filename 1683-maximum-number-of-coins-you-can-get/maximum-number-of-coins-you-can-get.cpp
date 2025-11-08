class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(), piles.end());
        int ans = 0;
        int n = piles.size();
        int j = n - 2;
        int counter = n / 3;
        
        while(counter){

            ans += piles[j];
            j -= 2;
            counter--;
        }

        return ans;
    }
};