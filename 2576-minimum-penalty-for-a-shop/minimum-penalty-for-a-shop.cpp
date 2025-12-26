class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();
        vector<int> suffixY(n+1, 0);
        vector<int> prefixN(n+1, 0);
        int minPenalty = INT_MAX;
        int ans = 0;

        for(int i = 1; i <= n; i++){

            prefixN[i] = prefixN[i - 1];
            suffixY[n - i] = suffixY[n - i + 1];
            if(customers[i - 1] == 'N') 
                prefixN[i]++;
            
            if(customers[n - i] == 'Y')
                suffixY[n - i]++;
        }

        for(int i = 0; i <= n; i++){
            int penalty = prefixN[i] + suffixY[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};