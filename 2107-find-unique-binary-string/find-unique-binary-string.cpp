class Solution {
private:

    int convert_number(string str) {

        int len = str.length();
        int num = 0;

        for(int i = len - 1; i >= 0; i--) {

            int bit = (str[i] == '0') ? 0 : 1;
            num = (num * 2) + bit;
        
        }
        
        return num;
    }

    string stringConversion(int num, int &n) {

        string ans = "";

        while(num) {

            int rem = num % 2;
            ans += to_string(rem);
            num /= 2;
        }

        while(ans.size() != n)
            ans += '0';
    
        return ans;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        int no_of_element = (2 << n);
        vector<int> elements(no_of_element, 0);

        for(string str: nums) {

            int num = convert_number(str);
            elements[num]++;
        }

        for(int i = 0; i < no_of_element; i++) {

            if(elements[i] == 0)
                return stringConversion(i, n);
        }

        return "-1";
    }
};