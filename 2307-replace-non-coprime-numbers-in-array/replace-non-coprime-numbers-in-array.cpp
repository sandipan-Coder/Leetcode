class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
    
        stack<long long> st;

        for(int num: nums){
            
            long long curr = num;
            while(!st.empty()){
                long long gcdOfTwo = __gcd(st.top(), curr);
                if(gcdOfTwo == 1)
                    break;

                curr = st.top() / gcdOfTwo * curr; // This is same as lcm(st.top, curr)
                st.pop();
            }
            st.push(curr);
        }

        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = (int)st.top();
            st.pop();
        }

        return ans;
    }
};