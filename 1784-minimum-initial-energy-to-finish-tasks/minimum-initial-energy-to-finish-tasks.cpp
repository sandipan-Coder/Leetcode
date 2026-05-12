class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int start = tasks[0][1];
        int bal = tasks[0][1] - tasks[0][0];
        int loan = 0;

        for (int i = 1; i < tasks.size(); i++) {
            int cost = tasks[i][0];
            int thresh = tasks[i][1];

            if (bal < thresh) {
                loan += thresh - bal;
                bal = thresh;
            }

            bal -= cost;
        }

        return start + loan;
    }
};