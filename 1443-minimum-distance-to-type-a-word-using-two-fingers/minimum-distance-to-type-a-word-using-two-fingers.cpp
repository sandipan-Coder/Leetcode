class Solution {

private:
    // distance between two chars
    int dist(char a, char b) {
        int x1 = (a - 'A') / 6, y1 = (a - 'A') % 6;
        int x2 = (b - 'A') / 6, y2 = (b - 'A') % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minimumDistance(string word) {
        
        int n = word.length();
        vector<int> dp(26, 0);
        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            char a = word[i], b = word[i + 1];
            int d = dist(a, b);
            total += d;

            vector<int> newDp(26, 0);

            for (int j = 0; j < 26; j++) {
                // same finger
                newDp[j] = max(newDp[j], dp[j]);

                // use second finger
                int saving = dp[j] + d - dist('A' + j, b);
                newDp[a - 'A'] = max(newDp[a - 'A'], saving);
            }

            dp = newDp;
        }

        int maxSaving = *max_element(dp.begin(), dp.end());
        return total - maxSaving;
    }
};