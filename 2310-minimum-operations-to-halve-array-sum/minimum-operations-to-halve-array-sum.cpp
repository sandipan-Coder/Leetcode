class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        int n = nums.size();
        double sum = 0;
        priority_queue<double> pq;
        int count = 0;

        for(int i = 0; i < n; i++){

            sum += nums[i];
            pq.push(nums[i]);
        }

        double half = sum / 2;

        while(sum > half){

            double ele = pq.top();
            pq.pop();

            sum -= ele;
            ele /= 2;
            pq.push(ele);
            sum += ele;

            count++;
        }

        return count;
    }
};