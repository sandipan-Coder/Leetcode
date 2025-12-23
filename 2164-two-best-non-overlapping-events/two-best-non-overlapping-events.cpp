class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        // Sort events by start time (then end time, then value)
        sort(events.begin(), events.end());

        // Min-heap: (endTime, value)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int maxVal = 0; // best value among events that have ended before current start
        int ans = 0;    // best sum of values of up to 2 non-overlapping events

        for (auto &event : events) {
            int srt = event[0];
            int end = event[1];
            int val = event[2];

            // Move all events that end before current start into maxVal
            while (!pq.empty() && pq.top().first < srt) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // Pick current event as 2nd event, pair it with best finished event
            ans = max(ans, maxVal + val);

            // Store current event for future events
            pq.push({end, val});
        }

        return ans;   
    }
};