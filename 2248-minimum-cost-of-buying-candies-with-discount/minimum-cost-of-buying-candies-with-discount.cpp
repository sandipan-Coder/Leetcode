class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int n = cost.size();
        int totalCost = 0;

        if(n == 1)
            return cost[0];

        if(n == 2)
            return (cost[0] + cost[1]);
        
        sort(cost.begin(), cost.end(), greater<int>());

        int skip = 2;
        for(int i = 0; i < n; i++) {

            if(i == skip) {
                skip += 3;
                continue;
            }

            totalCost += cost[i];
        }

        return totalCost;
    }
};