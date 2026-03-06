class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int n = s.length();
        int segments = 0;
        int i = 0;

        while(i < n) {

            if(s[i] == '1') {

                while(i < n && (s[i] == '1'))
                    i++;
                segments++;
            } 
            // else {
            //     while(i < n && (s[i] == '0'))
            //         i++;
            // }
            i++;
        }
        
        return (segments == 1);
    }
};