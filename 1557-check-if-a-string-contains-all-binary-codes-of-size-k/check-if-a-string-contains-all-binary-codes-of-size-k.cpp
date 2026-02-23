class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.length();
        if(n < k)
            return false;
        unordered_set<string> st;
        int noOfSub = pow(2, k);

        for(int i = k; i <= n; i++) {

            string str = s.substr(i-k, k);
            st.insert(str);

            if(st.size() == noOfSub)
                return true;
        }

        int size = st.size();
        return (size == noOfSub);
    }
};