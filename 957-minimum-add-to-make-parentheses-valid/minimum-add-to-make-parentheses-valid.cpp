class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int count = 0;

        for(char ch: s){
            if(ch == '(')
                st.push('(');
            else if(ch == ')' && st.empty())
                count++;
            else if(ch == ')' && (st.top() == '('))
                st.pop();
        }

        count += st.size();

        return count;
    }
};