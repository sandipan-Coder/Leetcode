class Solution {

private:

    double passRate(int pass, int total){

        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        double ans = 0;

        for(auto singleClass: classes){

            int pass = singleClass[0];
            int total = singleClass[1];

            double rateOfChange = passRate(pass, total);

            pq.push({rateOfChange, {pass, total}});
        }

        while(extraStudents){

            auto it = pq.top();
            pq.pop();

            double rateOfPass = it.first;
            int pass = it.second.first;
            int total = it.second.second;

            double rateOfChange = passRate(pass + 1, total + 1);

            pq.push({rateOfChange, {pass + 1, total + 1}});
            extraStudents--;
        }

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