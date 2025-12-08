class Solution {
public:
    int countTriples(int n) {
        
        if(n < 5)
            return 0;

        int count = 0;
        unordered_map<int, int> mp;

        for(int i = 1; i <= n; i++)
            mp[i * i] = i;
        
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){

                if(a == b)
                    continue;
                
                int sqrSum = (a * a) + (b * b);

                if(mp.count(sqrSum))
                    count++;
            }
        }

        return count;
    }
};