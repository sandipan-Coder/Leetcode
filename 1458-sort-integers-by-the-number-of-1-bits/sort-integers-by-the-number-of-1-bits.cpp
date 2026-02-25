class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [&](int &a, int &b){

            /*
            int count1 = __builtin_popcount(a);
            int count2 = __builtin_popcount(b);

            if(count1 == count2)
                return a < b;
            else if(count1 < count2)
                return a < b;
            else
                return b < a;
            */

            if(__builtin_popcount(a) == __builtin_popcount(b))
                return a < b;
            else
                return __builtin_popcount(a) < __builtin_popcount(b);
        });

        return arr;
    }
};