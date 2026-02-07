class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        stack<char> st;
        int count = 0;

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            if(st.empty())
                st.push(ch);
            else if((ch == st.top()) || (st.top() == 'a' && ch == 'b'))
                st.push(ch);
            else {
                st.pop();
                count++;
            }   
        }

        return count;
    }
};