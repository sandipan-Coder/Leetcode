class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        // Sort by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> dp(n);
        vector<int> endTimes(n);

        for (int i = 0; i < n; i++)
            endTimes[i] = jobs[i][1];

        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int incl = jobs[i][2];

            // Binary search for last job that doesn't overlap
            int j = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;
            if (j >= 0)
                incl += dp[j];

            dp[i] = max(dp[i - 1], incl);
        }

        return dp[n - 1];
    }
};