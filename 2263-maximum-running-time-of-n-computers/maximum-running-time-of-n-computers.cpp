class Solution {
private:

    bool isPossible(int n, long long target, vector<int>& batteries){

        long long sum = 0;

        for(int time: batteries)
            sum += min((long long)time, target);
        
        return (sum >= (n * target * 1LL));
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long left = LLONG_MAX;
        long long right = 0;
        long long sum = 0;

        for(int time: batteries){
            left = min(left, (long long)time);
            sum += time;
        }
        
        right = sum / n;

        while(left <= right){

            long long mid = left + (right - left) / 2;
            
            if(isPossible(n, mid, batteries))
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }
};