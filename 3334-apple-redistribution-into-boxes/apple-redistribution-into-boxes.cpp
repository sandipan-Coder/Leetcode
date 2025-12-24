class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        sort(capacity.begin(), capacity.end(), greater<>());
        int m = capacity.size();
        int totalApple = 0;
        int count = 0;

        for(int app: apple)
            totalApple += app;

        for(int i = 0; i < m; i++){
            totalApple -= capacity[i];
            count++;

            if(totalApple <= 0)
                break;
        }

        return count;
    }
};