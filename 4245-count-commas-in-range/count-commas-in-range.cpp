class Solution {
public:
    int countCommas(int n) {

        string str = to_string(n);
        int len = str.length();
        
        if(len < 4)
            return 0;

        int count = (n - 1000) + 1;

        return count;
    }
};