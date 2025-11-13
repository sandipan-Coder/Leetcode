class Solution {
public:
    int maxOperations(string s) {
        
        int operations = 0;
        int count = (s[0] == '1');
        int n = s.length();

        for(int i = 1; i < n; i++){

            if(s[i] == '1')
                count++;
            else if(s[i - 1] == '1')
                operations += count;
        }

        return operations;
    }
};