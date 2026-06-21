class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        int count = 0;

        if(costs[0] > coins)
            return 0;
        
        int total = coins;
        for(int cost: costs) {

            if(cost <= total) {
                count++;
                total -= cost;
            }
        }

        return count;
    }
};