class Solution {
public:
    int maxOperations(string s) {
        
        int operations = 0;
        int sequence = 0;
        int n = s.length();

        if(n == 1)
            return 0;
        int i = n - 1;

        if(s[i] == '1'){
            while(i >= 0 && s[i] == '1')
                i--;
        }

        while(i >= 0){

            if(s[i] == '1'){
                while(i >= 0 && s[i] == '1')
                    i--;
                sequence++;
            }
            i--;
        }

        i = 0;

        while(i < n  && sequence){

            if(s[i] == '1'){
                int count = 0;
                while(i < n && s[i] == '1'){
                    count++;
                    i++;
                }
                operations += (1LL * count * sequence);
                sequence--;
            }
            else
                i++;
        }

        return operations;
    }
};