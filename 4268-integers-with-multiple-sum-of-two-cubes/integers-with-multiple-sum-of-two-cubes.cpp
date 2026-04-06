class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        
        if(n < 1729)
            return {};

        unordered_map<int, int> mp;

        for(int i = 1; i <= 1000; i++) {
            for(int j = i; j <= 1000; j++) {

                int num = ((i * i * i) + (j * j * j));

                if(num > n)
                    break;
                
                mp[num]++;
            }
        }

        vector<int> ans;
        for(auto [num, freq]: mp){
            if(freq >= 2)
                ans.push_back(num);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};