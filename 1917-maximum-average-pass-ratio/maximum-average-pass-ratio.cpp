class Solution {
private:

    double passRatio(int pass, int total){

        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        

        for(auto singleClass: classes){
            int pass = singleClass[0];
            int total = singleClass[1];

            double rateOfChange = passRatio(pass, total);

            pq.push({rateOfChange, {pass, total}});
        }

        while(extraStudents){
            auto it = pq.top();
            pq.pop();

            double rateofPer = it.first;
            int pass = it.second.first;
            int total = it.second.second;

            double rateOfChange = passRatio(pass + 1, total + 1);
            pq.push({rateOfChange, {pass + 1, total + 1}});

            extraStudents--;
        }

        double ans = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int pass = it.second.first;
            int total = it.second.second;

            ans += (double)pass / total;
        }

        return ans / n;
    }
};