class Solution {
private:

    int reverseNum(int num){

        int ans = 0;

        while(num){
            int rem = (num % 10);
            ans = (ans * 10) + rem;
            num /= 10;
        }

        return ans;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return -1;

        unordered_map<int, int> mp;
        int dist = INT_MAX;
        
        for(int i = 0; i < n; i++) {

            int num = nums[i];
            if(mp.count(num)){

                int diff = (i - mp[num]);
                dist = min(dist, diff);
            }

            int rNum = reverseNum(num);
            mp[rNum] = i;
        }

        return (dist == INT_MAX) ? -1 : dist;
    }
};