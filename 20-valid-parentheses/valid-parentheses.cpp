class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char &ch: s){

            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                
                if(st.size() == 0)
                    return false;

                char top = st.top();
                st.pop();

                if((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                    return false;
            }
        }

        return (st.size() == 0);
    }
};