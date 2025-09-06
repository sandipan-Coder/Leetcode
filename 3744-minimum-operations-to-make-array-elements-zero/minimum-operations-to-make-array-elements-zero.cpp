class Solution {
private:

    long long solve(int l, int r){

        long long L = 1;
        long long S = 1;
        long long steps = 0;

        while(L <= r){

            long long R = L*4 - 1;

            long long start = max(L, (long long)l);
            long long end = min(R, (long long)r);

            if(start <= end)
                steps += (end - start + 1) * S;
            
            S++;
            L *= 4;
        }

        return steps;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        
        long long ans = 0;

        for(auto &querie: queries){

            int l = querie[0];
            int r = querie[1];

            long long steps = solve(l, r);

            ans += (steps + 1) / 2;
        }

        return ans;
    }
};