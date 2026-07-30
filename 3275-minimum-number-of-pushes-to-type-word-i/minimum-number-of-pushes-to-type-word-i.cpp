class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.length();

        if(n <= 8)
            return n;

        int extra = (n % 8);
        int ans = 0;

        int div = (n / 8);

        for(int i = 1; i <= div; i++)
            ans += (i * 8);
        
        ans += (extra * (div + 1));


        return ans;
    }
};