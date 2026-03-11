class Solution {
private:

    string numberToBinary(int n) {

        int num = n;
        string ans = "";

        while(num) {

            int bit = (num & 1);
            ans += to_string(bit);

            num = (num >> 1);
        }

        // reverse(ans.begin(), ans.end());

        // Remove starting 1's
        // int idx = 0;
        int len = ans.length() - 1;
        string sub;

        while(len >= 0 && ans[len] == '1')
            len--;
        
        if(len < 0)
            return "-1";
        else
            sub = ans.substr(0, len + 1);

        return sub;
    }


public:
    int bitwiseComplement(int n) {
        
        if(n == 0)
            return 1;

        string binary = numberToBinary(n);
        
        if(binary == "-1")
            return 0;
        
        // reverse(binary.begin(), binary.end());
        int len = binary.length();
        int ans = 0;

        for(int i = 0; i < len; i++) {

            if(binary[i] == '0'){
                int num = (1 << i);
                ans += num;
            }
        }

        return ans;
    }
};