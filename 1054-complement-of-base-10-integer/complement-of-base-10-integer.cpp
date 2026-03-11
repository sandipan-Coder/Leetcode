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

        reverse(ans.begin(), ans.end());

        // Remove starting 1's
        int idx = 0;
        int len = ans.length();
        string sub;

        while(idx < len && ans[idx] == '1')
            idx++;
        
        if(idx == len)
            return "-1";
        else
            sub = ans.substr(idx);

        return sub;
    }


public:
    int bitwiseComplement(int n) {
        
        if(n == 0)
            return 1;

        string binary = numberToBinary(n);
        
        if(binary == "-1")
            return 0;
        
        reverse(binary.begin(), binary.end());
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