class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();
        int sum = neededTime[0];
        int maxEle = neededTime[0];
        int time = 0;

        if(n == 1)
            return 0;

        for(int i = 1; i < n; i++){

            if(colors[i] == colors[i - 1]){
                sum += neededTime[i];
                maxEle = max(maxEle, neededTime[i]);
            }
            else{
                time += (sum - maxEle);
                sum = neededTime[i];
                maxEle = neededTime[i];
            }
                
        }

        time += (sum - maxEle);
        return time;
    }
};