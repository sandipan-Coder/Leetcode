class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long ans = 0;
        int count = k;
        priority_queue<int> pq(nums.begin(), nums.end());

        while(count) {

            int num = pq.top();
            pq.pop();

            // cout << num << " ";
            ans += num;
            int new_num = ceil(num / 3.0);
            pq.push(new_num);

            count--;
        }

        return ans;
    }
};