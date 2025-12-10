class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        
        int n = complexity.size();
        int MOD = 1e9 + 7;
        long ans = 1;

        // Iterate through the array starting from index 1
        for(int i = 1; i < n; i++){
            
            // Check if current element is less than or equal to the first element
            // If so, no valid permutation exists where first element is minimum
            if(complexity[i] <= complexity[0])
                return 0;
            

            // Multiply result by current index (counting valid positions)
            // Apply modulo to prevent overflow
            ans = (ans * i * 1LL) % MOD;
        }

        return ans;
    }
};