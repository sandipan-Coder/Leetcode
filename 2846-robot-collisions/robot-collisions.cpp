class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<int> copy_healths(begin(healths), end(healths));
        vector<int> actual_idx(n);
        iota(begin(actual_idx), end(actual_idx), 0);

        // Sort the actual_idx vector according to their sequence in positions vector.
        sort(begin(actual_idx), end(actual_idx), [&](int i, int j) {
            if(positions[i] < positions[j])
                return true;
            else
                return false;
        });

        stack<int> st;

        for(int &idx: actual_idx) {

            if(directions[idx] == 'R')
                st.push(idx);
            else {
                while(!st.empty() && copy_healths[idx] > 0) {

                    int top_idx = st.top();
                    st.pop();

                    if(copy_healths[top_idx] == copy_healths[idx]) {
                        copy_healths[top_idx] = 0;
                        copy_healths[idx] = 0; 
                    }
                    else if(copy_healths[top_idx] > copy_healths[idx]) {
                        copy_healths[idx] = 0;
                        copy_healths[top_idx] -= 1;
                        st.push(top_idx);
                    } 
                    else {
                        copy_healths[idx] -= 1;
                        copy_healths[top_idx] = 0;
                    }
                }
            }
        }

        // if(st.empty())
        //     return {};
        
        vector<int> ans;
        for(int health: copy_healths) {
            if(health != 0)
                ans.push_back(health);
        }

        return ans;
    }
};