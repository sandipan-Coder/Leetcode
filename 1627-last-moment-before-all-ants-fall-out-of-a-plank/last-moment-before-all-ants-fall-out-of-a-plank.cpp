class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int time = 0;

        for(int ele: left)
            time = max(time, (ele - 0));
        
        for(int ele: right)
            time = max(time, (n - ele));


        return time;
    }
};