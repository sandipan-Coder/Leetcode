class Solution {
private:

    int largestAreaHisto(vector<int> &histo){

        int n = histo.size();
        stack<int> st;
        int ans = 0;

        for(int i = 0; i < n; i++){

            while(!st.empty() && histo[st.top()] > histo[i]){

                int element = histo[st.top()];
                st.pop();
                int nsi = i;
                int psi = (st.empty() ? -1 : st.top());

                int area = element * (nsi - psi - 1);
                ans = max(ans, area);
            }
            st.push(i);
        }

        while(!st.empty()){

            int element = histo[st.top()];
            st.pop();
            int nsi = n;
            int psi = (st.empty() ? -1 : st.top());

            int area = element * (nsi - psi - 1);
            ans = max(ans, area);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> heightOfHisto(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(mat[i][j] == '1')
                    heightOfHisto[j]++;
                else
                    heightOfHisto[j] = 0;
            }

            int area = largestAreaHisto(heightOfHisto);
            ans = max(ans, area);
        }

        return ans;
    }
};